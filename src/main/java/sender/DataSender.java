package sender;

public class DataSender {

    public static void send(BatteryChargingParameters parameters) {
        System.out.println("Sending Battery/Charging parameters: " + parameters.getBatteryLevel() + " %, " + parameters.getChargingCurrent() + " A");
    }

}
