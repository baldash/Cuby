package com.keimyung.baldash.cuby.Handlers;

import android.view.GestureDetector;
import android.view.MotionEvent;

import com.keimyung.baldash.cuby.GameManager;
import com.keimyung.baldash.cuby.Misc.Constants;

public class InputManager extends GestureDetector.SimpleOnGestureListener
{
    private GameManager gameManager = null;

    public InputManager(GameManager gameManager)
    {
        this.gameManager = gameManager;
    }

    ///// OVERRIDES

    @Override
    public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY)
    {
        System.out.println("onFling");
        /*if (Math.abs(e1.getY() - e2.getY()) > Constants.SWIPE_MAX_OFF_PATH){
            return false;
        }*/

        if (e1.getY() - e2.getY() > Constants.SWIPE_MIN_DISTANCE
                && Math.abs(velocityY) > Constants.SWIPE_THRESHOLD_VELOCITY) {
            System.out.println("swipe up, distance: " + (e1.getY() - e2.getY()));
            gameManager.onSwipeUp((e1.getY() - e2.getY()), velocityY);
        }
        else if (e2.getY() - e1.getY() > Constants.SWIPE_MIN_DISTANCE
                && Math.abs(velocityY) > Constants.SWIPE_THRESHOLD_VELOCITY) {
            System.out.println("swipe down");
        }

        return super.onFling(e1, e2, velocityX, velocityY);
    }

    @Override
    public boolean onSingleTapConfirmed(MotionEvent e) {
        switch (e.getAction()) {
            case MotionEvent.ACTION_DOWN:
            case MotionEvent.ACTION_MOVE:
                System.out.println("input down");
                break;
        }

        return true;
    }

    // By default this method returns false and makes the gesture detector ignore all the inputs,
    // so we have to override it that way in order to make it work
    @Override
    public boolean onDown(MotionEvent e) {
        return true;
    }
}
