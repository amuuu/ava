class ProjectController
{
    public: 
        ProjectController();
        char* GetProjectName() const { return globalSettings.PROJECT_NAME; }

    private:
        struct GlobalSettings_t
        {
            int PROJECT_SAMPLE_RATE;
            float PROJECT_MASTER_VOLUME;
            float PROJECT_MASTER_PAN;
            char* PROJECT_NAME; 
        } globalSettings;
};