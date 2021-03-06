package com.keimyung.baldash.cuby.Misc;

import java.util.Random;

public enum EPlatformType
{
    NONE,
    BASIC,
    QUICK,
    GHOST,
    JUMPING,
    MOVING_V;

    private static final EPlatformType[] VALUES = values();
    private static final int SIZE = VALUES.length;
    private static final Random RANDOM = new Random();

    public static EPlatformType getRandomType() {

        return VALUES[1 + RANDOM.nextInt(SIZE - 1)];
    }
}
