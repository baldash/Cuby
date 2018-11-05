package com.keimyung.baldash.cuby;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.ImageView;
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
    ImageView platformPlaceholder;
    ImageView platformIcon;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        ResourcesHandler.getInstance().setResources(getResources());

        initAppConfig();
        initLayouts();

        setContentView(frameLayout);
        gameManager.setHUDElements(scoreText, cooldownText, platformIcon);

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
        platformIcon = new ImageView(this);
        platformPlaceholder = new ImageView(this);

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

        platformPlaceholder.setId(R.id.platformPlaceholderId);
        platformPlaceholder.setImageResource(R.drawable.platform_placeholder);
        
        platformIcon.setId(R.id.nexPlatformIconId);
        platformIcon.setImageResource(R.drawable.basicplatform);
        platformIcon.setVisibility(View.INVISIBLE);

        RelativeLayout.LayoutParams buttonParams = new RelativeLayout.LayoutParams(230, 230);
        RelativeLayout.LayoutParams scoreTextParams = new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        RelativeLayout.LayoutParams coolDownTextParams = new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        RelativeLayout.LayoutParams platformPlaceholderParams = new RelativeLayout.LayoutParams(155, 155);
        RelativeLayout.LayoutParams platformIconParams = new RelativeLayout.LayoutParams(115, 115);
        RelativeLayout.LayoutParams layoutParams = new RelativeLayout.LayoutParams(RelativeLayout.LayoutParams.MATCH_PARENT, RelativeLayout.LayoutParams.MATCH_PARENT);

        relativeLayout.setLayoutParams(layoutParams);
        relativeLayout.addView(jumpButton);
        relativeLayout.addView(scoreText);
        relativeLayout.addView(platformIcon);
        relativeLayout.addView(platformPlaceholder);
        relativeLayout.addView(cooldownText);

        buttonParams.addRule(RelativeLayout.ALIGN_PARENT_LEFT);
        buttonParams.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
        buttonParams.setMargins(30, 0, 0, 30);
        jumpButton.setLayoutParams(buttonParams);

        scoreTextParams.addRule(RelativeLayout.ALIGN_PARENT_RIGHT);
        scoreTextParams.addRule(RelativeLayout.ALIGN_PARENT_TOP);
        scoreText.setLayoutParams(scoreTextParams);

        platformPlaceholderParams.addRule(RelativeLayout.CENTER_HORIZONTAL);
        platformPlaceholderParams.addRule(RelativeLayout.ALIGN_PARENT_TOP);
        platformPlaceholderParams.setMargins(0, 15, 0, 0);
        platformPlaceholder.setLayoutParams(platformPlaceholderParams);

        coolDownTextParams.addRule(RelativeLayout.CENTER_HORIZONTAL);
        coolDownTextParams.addRule(RelativeLayout.ALIGN_PARENT_TOP);
        coolDownTextParams.addRule(RelativeLayout.RIGHT_OF, R.id.platformPlaceholderId);
        coolDownTextParams.addRule(RelativeLayout.CENTER_VERTICAL, R.id.platformPlaceholderId);
        cooldownText.setLayoutParams(coolDownTextParams);

        platformIconParams.addRule(RelativeLayout.CENTER_HORIZONTAL);
        platformIconParams.addRule(RelativeLayout.ALIGN_PARENT_TOP);
        platformIconParams.setMargins(0, 30, 0, 0);
        platformIcon.setLayoutParams(platformIconParams);

        frameLayout.addView(gameManager);
        frameLayout.addView(relativeLayout);
    }
}
