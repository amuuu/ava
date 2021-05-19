#pragma once

#include <string>
#include <stdlib.h>

#define SCALE_NOTES_SIZE 7

/* STRUCTS */

struct Settings
{
    int scaleType; // 1->minor / 2->major
    int baseNote; // c2->36 / c8->88
    int numOctaves; // ->3

    int GetBaseNote() { return baseNote; }
    int GetNumOctaves() { return numOctaves; }
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
        int scaleType, baseNote, numOctaves;

        Scale scale;
    
        // TODO: Turn this to a list rather than it being a single progression
        ChordProgression progression;


        Composer(int scaleType, int baseNote, int numOctaves)
        {
            this->scaleType = scaleType;
            this->baseNote = baseNote;
            this->numOctaves = numOctaves;

            if (this->scaleType == 1)
                scale = MinorScale(baseNote, numOctaves);
            else if (this->scaleType == 2)
                scale = MajorScale(baseNote, numOctaves);
            

        }

        Note* GetChordInProgression(int index)
        {
            Chord tmpChord = scale.GetScaleNote(index).chord;
            

            Note* chordBaseNotes = new Note[tmpChord.length];
            int* chordNoteIndexes = tmpChord.GetNoteIndexes();
            for (int i = 0; i < tmpChord.length; i++)
            {
                chordBaseNotes[i] = Note(chordBaseNotes[i]);
            }

             // base note might be buggy
            return ExpandToOctaves(chordBaseNotes, scale.settings.GetBaseNote(), scale.settings.numOctaves);
        }

        Note* GetNextChord() 
        {
            Note* result = GetChordInProgression(progression.currentIndex);
            progression.currentIndex++;
            if (progression.currentIndex > progression.length)
                progression.currentIndex = 0;

            return result;
        }


        Note* GetRandomChordInScale()
        {
            srand(time(0));
            int index = rand() % SCALE_NOTES_SIZE;
            return GetChordInProgression(index);
        }
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
        int type;

    public:    
        int length;
        
        int* GetNoteIndexes()
        {
            return noteIdexes;
        }

};

class MinorChord : public Chord
{
    public:
        MinorChord(int baseNoteIndex, ScaleNote* scaleNotes)
        {
            type = 1;
            
            length = 3;
            noteIdexes = new int[length]; // bug potential
            
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
            type = 2;

            length = 3;
            noteIdexes = new int[length]; // bug potential
            
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
            type = 3; 

            length = 3;
            noteIdexes = new int[length]; // bug potential
            
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

    public:
        Settings settings;


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

        ScaleNote GetScaleNote(int index)
        {
            return notes[index];
        }

};

class MinorScale : public Scale
{
    public:
        MinorScale(int baseNote, int numOctaves)
        {
            settings.scaleType = 1;
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
        MajorScale(int baseNote, int numOctaves)
        {
            settings.scaleType = 2;
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

Note* ExpandToOctaves(Note* notes, int baseNote, int numOctaves)
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
