package com.keimyung.baldash.cuby;

import android.app.Activity;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.Gravity;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.RelativeLayout;

import com.keimyung.baldash.cuby.Handlers.ResourcesHandler;
import com.keimyung.baldash.cuby.Misc.Constants;

public class MainActivity extends Activity {

    GameManager gameManager; // game surface
    RelativeLayout relativeLayout; // widgets surface (buttons)
    FrameLayout frameLayout; // holder for both game and relative layouts
    Button jumpButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        ResourcesHandler.getInstance().setResources(getResources());

        initAppConfig();
        initLayouts();

        setContentView(frameLayout);

        jumpButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                gameManager.getPlayer().doJump();
            }
        });
    }

    private void initAppConfig()
    {
        // Hide android studio toolbar and title
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);

        DisplayMetrics dm = new DisplayMetrics();

        getWindowManager().getDefaultDisplay().getMetrics(dm);
        Constants.SCREEN_HEIGHT = dm.heightPixels;
        Constants.SCREEN_WIDTH = dm.widthPixels;
    }

    private void initLayouts()
    {
        jumpButton = new Button(this);
        gameManager = new GameManager(this);
        frameLayout = new FrameLayout(this);
        relativeLayout = new RelativeLayout(this);

        jumpButton.setId(R.id.jumpButtonId);
        jumpButton.setBackgroundResource(R.drawable.up_arrow_green);

        RelativeLayout.LayoutParams buttonParams = new RelativeLayout.LayoutParams(230, 230);
        RelativeLayout.LayoutParams layoutParams = new RelativeLayout.LayoutParams(RelativeLayout.LayoutParams.MATCH_PARENT, RelativeLayout.LayoutParams.MATCH_PARENT);

        relativeLayout.setLayoutParams(layoutParams);
        relativeLayout.addView(jumpButton);

        buttonParams.addRule(RelativeLayout.ALIGN_PARENT_LEFT);
        buttonParams.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
        buttonParams.setMargins(30, 0, 0, 30);
        jumpButton.setLayoutParams(buttonParams);

        frameLayout.addView(gameManager);
        frameLayout.addView(relativeLayout);
    }
}
