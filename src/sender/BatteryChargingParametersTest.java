package sender;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;


import static org.junit.Assert.assertEquals;

public class BatteryChargingParametersTest {
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



