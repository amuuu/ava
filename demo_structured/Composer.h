#pragma once

#include <string>
#include <list>

class Note
{
    public:
        int number;

        Note(int n)
        {
            number = n;
        }
};



class Chord
{
    protected:
        std::list<Note>* notes;
        std::string typeName;
    
    public:
        Chord(std::string typeName, int baseNoteIndex, Note* scale)
        {
            notes = new std::list<Note>;

            typeName = typeName;
        }

        std::list<Note>* GetChordNotes(int baseNote, int numOctaves)
        {
            return ExpandNotesIntoOctaves(notes, baseNote, numOctaves);
        }

};

class MinorChord : public Chord
{
    public:
        MinorChord(int baseNoteIndex, std::list<Note>* scale) : Chord("m", baseNoteIndex, scale)
        {
            std::list<Note>::iterator it = scale->begin();
            
            std::advance(it, baseNoteIndex % 7);
            Note n1(it->number);
            notes->push_back(n1);

            it = scale->begin();
            std::advance(it, (baseNoteIndex+2) % 7);
            Note n2(it->number);
            notes->push_back(n2);

            it = scale->begin();
            std::advance(it, (baseNoteIndex+4) % 7);
            Note n3(it->number);
            notes->push_back(n3);
        }
};


static std::list<Note>* ExpandNotesIntoOctaves(std::list<Note>* notes, int baseNote, int numOctaves)
{
    
    int size = notes->size() * numOctaves;
    std::list<Note>* result = new std::list<Note>;
    
    for (int i = 0; i < size; i++)
    {
        std::list<Note>::iterator it = notes->begin();
        std::advance(it, i % notes->size());

        int newNoteNumber = baseNote + it->number + 12 * ((i / numOctaves));

        Note newNote(newNoteNumber);
        result->push_back(newNote);
    }

    return result;
}
