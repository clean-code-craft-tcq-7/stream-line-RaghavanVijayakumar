package sender;
public class BatteryChargingParameters {
    private double batteryLevel;
    private double chargingCurrent;

    public BatteryChargingParameters(double batteryLevel, double chargingCurrent) {
        this.batteryLevel = batteryLevel;
        this.chargingCurrent = chargingCurrent;
    }

    public double getBatteryLevel() {
        return batteryLevel;
    }

    public double getChargingCurrent() {
        return chargingCurrent;
    }
}