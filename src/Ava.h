/** @file Ava.h
	@brief Main class of the engine which manages the states and their transitions as well as managing the tracks
	@author AMU <a@b.c>
*/
/*
*
*
*
*
*
*/

#include "IOController.h"

enum EngineState {StartingState, HaltState,
                  OutputPlaybackState, InputPlaybackOnlyState,
                  RecordingState };

class AvaState;

class Ava
{
    public:
        Ava();        
        bool SetState(EngineState newState);
    
    private:
        AvaState currentState;
        IOController io;
};


/* This abstract class is used for composing behavior based on states and their transitions aka managing the fsm */
class AvaState
{
    public:
        AvaState() {}
        inline EngineState GetState() const { return stateName; }

        virtual bool PerformTransition(IOController io);

    protected:    
        EngineState stateName;
        void SetStateName(EngineState givenStateName) { stateName = givenStateName; }
};

class Halt: public AvaState
{
    public:
        Halt() { SetStateName(HaltState); }    
        bool PerformTransition(IOController io);
};

class OutputPlayback: public AvaState
{
    public:
        OutputPlayback() { SetStateName(OutputPlaybackState); }
        bool PerformTransition(IOController io);
};

class Starting: public AvaState
{
    public:
        Starting() { SetStateName(StartingState);  }    
        bool PerformTransition(IOController io);
};