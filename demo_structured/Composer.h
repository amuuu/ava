#pragma once

#include <string>
#include <list>

#define SCALE_NOTES_SIZE 7

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



class Note
{
    public:
        int number;

        Note(int n)
        {
            number = n;
        }
};

class ScaleNote : public Note
{
    public:
        Chord chord;

        ScaleNote(int number) : Note(number)
        {

        }
};

class Chord
{
    protected:
        Note notes[];


};



class Scale
{
    protected:
        ScaleNote* notes;
        Settings settings;

    public:
        
        Scale (Settings settings)
        {
            settings = settings;
        }

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

        virtual void SetNotesAndChords()
        { 
            printf("bruh"); 
        }

};

Note* ExpandToOctaves(ScaleNote* notes, int baseNote, int numOctaves)
{
    
    int size = SCALE_NOTES_SIZE * numOctaves;
    Note* resultNotes = new Note(size);

    for (int i = 0; i < size; i++)
    {
        int newNoteNumber = baseNote + notes[i % SCALE_NOTES_SIZE].number + 12 * ((i / numOctaves));

        Note newNote(newNoteNumber);
        resultNotes[i] = newNote;
    }

    return resultNotes;
}
