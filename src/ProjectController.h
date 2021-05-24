/** @file ProjectController.h
	@brief Main controller for different tracks and their states inside a project
*/
/*
*   This header contains methods for creating and managing a project with multiple tracks,
*   as well as providing ways to change the general settings of the project.
*/

#pragma once

#include "Track.h"
#include <string>

#include "AudioDataStructs.h"
#include "util/MathStaticFuncs.h"

class ProjectController
{
    public: 
        ProjectController();

        Track* GetTrack(int trackIndex);        
        bool AppendTrack(Track newTrack);
        bool RemoveTrack(Track toBeRemovedTrack) { return true; }
        bool AppendTrack();
        int GetTracksSize() { return tracks->size(); }

        std::list<Track>* GetAllTracks() const { return tracks; }

        float GetNextProjectSample();

        std::string GetProjectName() const { return globalSettings.PROJECT_NAME; }

    private:
        std::list<Track>* tracks;

        struct GlobalSettings_t
        {
            int PROJECT_SAMPLE_RATE;
            float PROJECT_MASTER_VOLUME;
            float PROJECT_MASTER_PAN;
            float PROJET_MASTER_BPM;
            std::string PROJECT_NAME; 
        } globalSettings;

        int GetNumActiveTracks();
};