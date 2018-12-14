package com.keimyung.baldash.cuby.Handlers;

import android.graphics.PointF;

import com.keimyung.baldash.cuby.GameManager;
import com.keimyung.baldash.cuby.GameObjects.Collectable;
import com.keimyung.baldash.cuby.MainThread;
import com.keimyung.baldash.cuby.Misc.Constants;
import com.keimyung.baldash.cuby.Misc.ECollectableType;

import java.util.Random;

import javax.vecmath.Vector2d;

public class CollectableHandler 
{
    private float totalTime;
    private int scoreBonus;
    private int collectableId;

    private GameManager gameManager;

    public CollectableHandler(GameManager gameManager)
    {
        this.gameManager = gameManager;
    }

    ///// GETTERS

    public int getScoreBonus()
    {
        return scoreBonus;
    }

    ///// METHODS

    public void update()
    {
        totalTime += MainThread.getDeltaTime();

        if (totalTime >= 5)
        {
            totalTime = 0;
            spawnCollectable();
        }
    }
    
    public void spawnCollectable()
    {
        ECollectableType collectableType = generateCollectableType();

        if (collectableType != ECollectableType.NONE)
        {
            Vector2d velocity = new Vector2d(GameManager.getGameSpeed().x * 0.70, GameManager.getGameSpeed().y);
            String name = "collectable " + collectableId;
            PointF pos = generateCollectablePos();

            EntitiesHandler.getInstance().addEntity(name, new Collectable(pos, collectableType, velocity, this));
            collectableId++;
        }
    }

    public ECollectableType generateCollectableType()
    {
        Random random = new Random();
        int spawnValue = random.nextInt(100);

        if (spawnValue >= 0 && spawnValue <= 40)
            return ECollectableType.NONE;
        else if (spawnValue > 40 && spawnValue <= 65)
            return ECollectableType.MALUS;
        else if (spawnValue > 65 && spawnValue <= 90)
            return ECollectableType.BONUS;
        else
            return ECollectableType.BONUSL;
    }

    private PointF generateCollectablePos()
    {
        Random random = new Random();
        float x = Constants.SCREEN_WIDTH;
        float y = 50 + random.nextFloat() * ((Constants.SCREEN_HEIGHT - 50) - 50);

        return new PointF(x, y);
    }

    public void addBonusPoints(int value)
    {
        scoreBonus += value;
        gameManager.updateScoreText();
    }
}
