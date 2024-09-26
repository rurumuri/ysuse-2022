package com.al_1suyan.utils;

import java.math.BigDecimal;

public class WebUtils {

    public static BigDecimal bigdecimal(String str, BigDecimal defaultValue) {
        try {
            return new BigDecimal(str);
        } catch (Exception e) {
            //e.printStackTrace();
        }
        return defaultValue;
    }


    public static int parseInt(String string, int defaultValue) {
        try {
            return Integer.parseInt(string);
        } catch (NumberFormatException e) {
            //e.printStackTrace();
        }
        return defaultValue;
    }


}
