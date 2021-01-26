/** @file Ava.h
	@brief Main header file of the engine which manages the states and their transitions as well as managing the tracks
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
#include "ProjectController.h"

#include "PortAudioDataStructs.h"
#include "MathStaticFuncs.h"

#include <map>


enum EngineState {StartingState, HaltState, OutputPlaybackState, InputPlaybackOnlyState, RecordingState };


/**************************************************
 *                  STATE CLASSES
 * ************************************************/
class AvaState
{
    /* 
    * This abstract class is used for composing behavior based
    * on states and their transitions aka managing the fsm.
    */
    public:
        AvaState() {}
        inline EngineState GetStateName() const { return stateName; }

        virtual bool PerformTransition(IOController io) { return false; }

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




/**************************************************
 *                  MAIN CLASS
 * ************************************************/
class Ava
{
    public:
        Ava();        
        bool SetState(EngineState newState);
        // EngineState GetCurrentState() { return currentState->GetStateName(); }
        bool UpdateOutputBufferData();
        
        ProjectController project;

    private:
        AvaState* currentState;
        IOController io;

        Halt haltInstance; OutputPlayback outputPlaybackInstance; Starting startingInstance;
        std::map<EngineState, AvaState*> statesMap { {HaltState, &haltInstance}, {OutputPlaybackState, &outputPlaybackInstance}, {StartingState, &startingInstance}};

};

