#include "Track.h"

class ProjectController
{
    public: 
        ProjectController();
        char* GetProjectName() const { return globalSettings.PROJECT_NAME; }

        bool AppendTrack(Track newTrack) {}
        bool RemoveTrack(Track toBeRemovedTrack) {}

    private:
        std::list<Track> tracks;

        struct GlobalSettings_t
        {
            int PROJECT_SAMPLE_RATE;
            float PROJECT_MASTER_VOLUME;
            float PROJECT_MASTER_PAN;
            char* PROJECT_NAME; 
        } globalSettings;
};