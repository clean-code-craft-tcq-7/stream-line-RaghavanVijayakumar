package sender;

public class BatterySimulator {

	 public static void main(String[] args) {
		 for(int i=1;i<50;i++) {
	        BatteryChargingParameters parameters = DataGenerator.generate();
	        DataSender.send(parameters);
		 }
	    }
}
