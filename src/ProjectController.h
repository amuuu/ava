#include "Track.h"
#include <string>

class ProjectController
{
    public: 
        ProjectController();

        Track GetTrack(int trackIndex);        
        bool AppendTrack(Track newTrack);
        bool RemoveTrack(Track toBeRemovedTrack) { return true; }
        bool AppendTrack();

        std::list<Track> GetAllTracks() const { return tracks; }

        
        std::string GetProjectName() const { return globalSettings.PROJECT_NAME; }

    private:
        std::list<Track> tracks;

        struct GlobalSettings_t
        {
            int PROJECT_SAMPLE_RATE;
            float PROJECT_MASTER_VOLUME;
            float PROJECT_MASTER_PAN;
            std::string PROJECT_NAME; 
        } globalSettings;
};