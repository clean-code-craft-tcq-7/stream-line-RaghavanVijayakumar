package sender;

import java.util.Random;
public class DataGenerator extends BatteryChargingParameters{
	
private static double batteryLevel;
private static double chargingCurrent;
private static double[] generatedata=new double[50];


public DataGenerator(double batteryLevel, double chargingCurrent) {
		super(batteryLevel, chargingCurrent);
		// TODO Auto-generated constructor stub
	}

public static BatteryChargingParameters generate() {
    Random random = new Random();
    float batteryLevel = random.nextFloat() * 100.0f;
    float chargingCurrent = random.nextFloat() * 5.0f;
    return new BatteryChargingParameters(batteryLevel, chargingCurrent);
}
}
