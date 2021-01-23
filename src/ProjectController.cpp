#include "ProjectController.h"

ProjectController::ProjectController()
{
    globalSettings.PROJECT_SAMPLE_RATE = 44100;
    globalSettings.PROJECT_NAME = "PURE AVA";


    Track mainTrack;
    tracks.push_back(mainTrack);
}

bool ProjectController::AppendTrack(Track newTrack)
{
    tracks.push_back(newTrack);
    
    return true;
}

Track ProjectController::GetTrack(int trackIndex)
{
    std::list<Track>::iterator it = tracks.begin();
    std::advance(it, trackIndex);
    return *it;
}