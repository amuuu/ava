#pragma once

#include <string>
#include <list>

#define SCALE_NOTES_SIZE 7

/* STRUCTS */

struct Settings
{
    int scaleType; // 1->minor / 2->major
    int baseNote; // c2->36 / c8->88
    int numOctaves; // -> 3
};

struct ChordProgression
{
    int length;
    int* chords; // index respective to the index of the notes inside scale.
    int currentIndex;
};

/* CONTROLLER CLASS */

class Composer
{
    public:
        Scale scale;
        ChordProgression progression;

        Note[] GetNextChord()
        {
            return scale.notes[progression.currentIndex].chord progression.chords[]    
        }

        Note[] GetRandomChordInScale() { }
};


/* NOTE */

class Note
{
    public:
        int number;

        Note() {}
        
        Note(int n)
        {
            number = n;
        }
};

class ScaleNote : public Note
{
    public:
        Chord chord;

        ScaleNote()
        {

        }
        
        ScaleNote(int number) : Note(number)
        {

        }
};



/* CHORDS */
// TODO: Make sure the chord formulas are right.

class Chord
{
    protected:
        int* noteIdexes;

};

class MinorChord : public Chord
{
    public:
        MinorChord(int baseNoteIndex, ScaleNote* scaleNotes)
        {
            noteIdexes = new int[3]; // bug potential
            
            noteIdexes[0] = scaleNotes[baseNoteIndex % SCALE_NOTES_SIZE].number;
            noteIdexes[1] = scaleNotes[(baseNoteIndex + 2) % SCALE_NOTES_SIZE].number;
            noteIdexes[2] = scaleNotes[(baseNoteIndex + 4) % SCALE_NOTES_SIZE].number;
        }
};

class MajorChord : public Chord
{
    public:
        MajorChord(int baseNoteIndex, ScaleNote* scaleNotes)
        {
            noteIdexes = new int[3]; // bug potential
            
            noteIdexes[0] = scaleNotes[baseNoteIndex % SCALE_NOTES_SIZE].number;
            noteIdexes[1] = (scaleNotes[(baseNoteIndex + 2) % SCALE_NOTES_SIZE].number - 1) % 12;
            noteIdexes[2] = scaleNotes[(baseNoteIndex + 4) % SCALE_NOTES_SIZE].number;
        }
};

class DimChord : public Chord
{
    public:
        DimChord(int baseNoteIndex, ScaleNote* scaleNotes)
        {
            noteIdexes = new int[3]; // bug potential
            
            noteIdexes[0] = scaleNotes[baseNoteIndex % SCALE_NOTES_SIZE].number;
            noteIdexes[1] = scaleNotes[(baseNoteIndex + 2) % SCALE_NOTES_SIZE].number;
            noteIdexes[2] = scaleNotes[(baseNoteIndex + 4) % SCALE_NOTES_SIZE].number;
        }
};



/* SCALES */

class Scale
{
    protected:
        ScaleNote* notes;
        Settings settings;

    public:
        
        virtual void SetNotesAndChords() {}
        
        bool IsNoteInScale(int noteNumber)
        {
            for(int i = 0; i < SCALE_NOTES_SIZE; i++)
            {
                if (noteNumber % 12 == notes[i].number) // bug potential
                {
                    return true;
                }
            }
            return false;
        }

        Note* GetScaleNotes()
        {
            return ExpandToOctaves(notes, settings.baseNote, settings.numOctaves);            
        }

};

class MinorScale : public Scale
{
    public:
        MinorScale(int scaleType, int baseNote, int numOctaves)
        {
            settings.scaleType = scaleType;
            settings.baseNote = baseNote;
            settings.numOctaves = numOctaves;

            SetNotesAndChords();
        }

        void SetNotesAndChords() override
        {
            notes = new ScaleNote[SCALE_NOTES_SIZE];
            
            notes[0] = ScaleNote(0);
            notes[1] = ScaleNote(2);
            notes[2] = ScaleNote(3);
            notes[3] = ScaleNote(5);
            notes[4] = ScaleNote(7);
            notes[5] = ScaleNote(8);
            notes[6] = ScaleNote(10);

            notes[0].chord = MinorChord(0, notes);
            notes[1].chord = DimChord(1, notes);
            notes[2].chord = MajorChord(2, notes);
            notes[3].chord = MinorChord(3, notes);
            notes[4].chord = MinorChord(4, notes);
            notes[5].chord = MajorChord(5, notes);
            notes[6].chord = MajorChord(6, notes);
        }
};

class MajorScale : public Scale
{
    public:
        MajorScale(int scaleType, int baseNote, int numOctaves)
        {
            settings.scaleType = scaleType;
            settings.baseNote = baseNote;
            settings.numOctaves = numOctaves;

            SetNotesAndChords();
        }

        void SetNotesAndChords() override
        {
            notes = new ScaleNote[SCALE_NOTES_SIZE];
            
            notes[0] = ScaleNote(0);
            notes[1] = ScaleNote(2);
            notes[2] = ScaleNote(4);
            notes[3] = ScaleNote(5);
            notes[4] = ScaleNote(7);
            notes[5] = ScaleNote(9);
            notes[6] = ScaleNote(10);

            notes[0].chord = MajorChord(0, notes);
            notes[1].chord = MinorChord(1, notes);
            notes[2].chord = MinorChord(2, notes);
            notes[3].chord = MajorChord(3, notes);
            notes[4].chord = MajorChord(4, notes);
            notes[5].chord = MinorChord(5, notes);
            notes[6].chord = DimChord(6, notes);
        }
};



/* UTILITY FUNCTIONS */

Note* ExpandToOctaves(ScaleNote* notes, int baseNote, int numOctaves)
{
    
    int size = SCALE_NOTES_SIZE * numOctaves;
    Note* resultNotes = new Note[size];

    for (int i = 0; i < size; i++)
    {
        int newNoteNumber = baseNote + notes[i % SCALE_NOTES_SIZE].number + 12 * ((i / numOctaves));

        Note newNote(newNoteNumber);
        resultNotes[i] = newNote;
    }

    return resultNotes;
}
