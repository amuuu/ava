/** @file ProjectController.h
	@brief Main controller for different tracks and their states inside a project
*/
/*
*   This header contains methods for creating and managing a project with multiple tracks,
*   as well as providing ways to change the general settings of the project.
*/

#include "Track.h"
#include <string>

class ProjectController
{
    public: 
        ProjectController();

        Track* GetTrack(int trackIndex);        
        bool AppendTrack(Track newTrack);
        bool RemoveTrack(Track toBeRemovedTrack) { return true; }
        bool AppendTrack();

        int GetNumActiveTracks();

        std::list<Track>* GetAllTracks() const { return tracks; }

        
        std::string GetProjectName() const { return globalSettings.PROJECT_NAME; }

    private:
        std::list<Track>* tracks;

        struct GlobalSettings_t
        {
            int PROJECT_SAMPLE_RATE;
            float PROJECT_MASTER_VOLUME;
            float PROJECT_MASTER_PAN;
            std::string PROJECT_NAME; 
        } globalSettings;
};