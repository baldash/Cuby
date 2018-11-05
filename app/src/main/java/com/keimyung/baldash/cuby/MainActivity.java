package com.keimyung.baldash.cuby;

import android.app.Activity;
import android.content.res.ColorStateList;
import android.graphics.Color;
import android.icu.text.RelativeDateTimeFormatter;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;

import com.keimyung.baldash.cuby.Handlers.ResourcesHandler;
import com.keimyung.baldash.cuby.Misc.Constants;

public class MainActivity extends Activity {

    GameManager gameManager; // game surface
    RelativeLayout relativeLayout; // widgets surface (buttons)
    FrameLayout frameLayout; // holder for both game and relative layouts

    Button jumpButton;
    TextView scoreText;
    TextView cooldownText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        ResourcesHandler.getInstance().setResources(getResources());

        initAppConfig();
        initLayouts();

        setContentView(frameLayout);
        gameManager.setHUDElements(scoreText, cooldownText);

        jumpButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!gameManager.gameStarted())
                    gameManager.startGame();
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
        scoreText = new TextView(this);
        cooldownText = new TextView(this);
        gameManager = new GameManager(this);
        frameLayout = new FrameLayout(this);
        relativeLayout = new RelativeLayout(this);

        jumpButton.setId(R.id.jumpButtonId);
        jumpButton.setBackgroundResource(R.drawable.up_arrow_green);

        scoreText.setId(R.id.scoreTextId);
        scoreText.setText("0");
        scoreText.setTextSize(22);
        scoreText.setTextColor(Color.BLUE);
        
        cooldownText.setId(R.id.countDownTextId);
        cooldownText.setText("0");
        cooldownText.setTextSize(22);
        cooldownText.setTextColor(Color.BLUE);

        RelativeLayout.LayoutParams buttonParams = new RelativeLayout.LayoutParams(230, 230);
        RelativeLayout.LayoutParams scoreTextParams = new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        RelativeLayout.LayoutParams coolDownTextParams = new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        RelativeLayout.LayoutParams layoutParams = new RelativeLayout.LayoutParams(RelativeLayout.LayoutParams.MATCH_PARENT, RelativeLayout.LayoutParams.MATCH_PARENT);

        relativeLayout.setLayoutParams(layoutParams);
        relativeLayout.addView(jumpButton);
        relativeLayout.addView(scoreText);
        relativeLayout.addView(cooldownText);

        buttonParams.addRule(RelativeLayout.ALIGN_PARENT_LEFT);
        buttonParams.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
        buttonParams.setMargins(30, 0, 0, 30);
        jumpButton.setLayoutParams(buttonParams);

        scoreTextParams.addRule(RelativeLayout.ALIGN_PARENT_RIGHT);
        scoreTextParams.addRule(RelativeLayout.ALIGN_PARENT_TOP);
        scoreText.setLayoutParams(scoreTextParams);

        coolDownTextParams.addRule(RelativeLayout.CENTER_HORIZONTAL);
        coolDownTextParams.addRule(RelativeLayout.ALIGN_PARENT_TOP);
        cooldownText.setLayoutParams(coolDownTextParams);

        frameLayout.addView(gameManager);
        frameLayout.addView(relativeLayout);
    }
}
