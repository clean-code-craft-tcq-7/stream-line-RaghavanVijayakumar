package sender;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class BatteryChargingParameterTest {

	@Test
	  public void testGenerateAndSend() {
        for (int i = 0; i < 50; i++) {
            BatteryChargingParameters params = DataGenerator.generate();
            String expected = "Sending Battery/Charging parameters: " + params.getBatteryLevel() + " %, " + params.getChargingCurrent() + " A";
            DataSender.send(params);
            assertEquals(expected, captureOutput(()->DataSender.send(params)));
            assertTrue(true);
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
