package test;

<<<<<<< HEAD:src/test/BatteryChargingParameterTest.java
import static org.junit.Assert.assertEquals;
import static org.junit.jupiter.api.Assertions.*;

=======
>>>>>>> b8ae7a02dde3ee295cc71b807bf47e225a0c1025:src/sender/BatteryChargingParametersTest.java
import org.junit.Test;

import sender.BatteryChargingParameters;
import sender.DataGenerator;
import sender.DataSender;

class BatteryChargingParameterTest {

	@Test
	  public void testGenerateAndSend() {
        for (int i = 0; i < 50; i++) {
            BatteryChargingParameters params = DataGenerator.generate();
            String expected = "Sending Battery/Charging parameters: " + params.getBatteryLevel() + " %, " + params.getChargingCurrent() + " A";
            assertEquals(expected, captureOutput(() -> DataSender.send(params)));
        }
    }

    private static String captureOutput(Runnable action) {
        java.io.ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
        java.io.PrintStream oldOut = System.out;
        System.setOut(new java.io.PrintStream(out));
        try {
            action.run();
        } finally {
            System.setOut(oldOut);
        }
        return out.toString().trim();
    }

}
