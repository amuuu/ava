class ProjectController
{
    public: 
        struct GlobalSettings_t
        {
            int PROJECT_SAMPLE_RATE;
            float PROJECT_MASTER_VOLUME;
            float PROJECT_MASTER_PAN;
            char* PROJECT_NAME; 
        } globalSettings;

        ProjectController();

        char* GetProjectName() const { return globalSettings.PROJECT_NAME; }
};