
#ifdef __cplusplus
extern "C"
{
#endif

    void updateSensor(void);
    int getTemperature(void);
    int getHumidity(void);
    void setupBme280(void);

#ifdef __cplusplus
}
#endif