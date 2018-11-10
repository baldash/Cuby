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

public class MainActivity extends Activity
{
    GameManager gameManager; // game surface
    RelativeLayout relativeLayout; // widgets surface (buttons)
    FrameLayout frameLayout; // holder for both game and relative layouts

    Button jumpButton;
    TextView scoreText;
    TextView coolDownText;
    ImageView platformPlaceholder;
    ImageView platformIcon;
    Button retryButton;
    TextView bestScore;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        ResourcesHandler.getInstance().setResources(getResources());

        initAppConfig();
        initLayouts();

        setContentView(frameLayout);
        gameManager.setHUDElements(scoreText, coolDownText, platformIcon, retryButton, bestScore);

        jumpButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!gameManager.gameStarted())
                    gameManager.startGame();
                gameManager.getPlayer().doJump();
            }
        });

        retryButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                gameManager.initGame();
                retryButton.setVisibility(View.INVISIBLE);
                bestScore.setVisibility(View.INVISIBLE);
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
        coolDownText = new TextView(this);
        platformIcon = new ImageView(this);
        retryButton = new Button(this);
        platformPlaceholder = new ImageView(this);
        bestScore = new TextView(this);

        gameManager = new GameManager(this);
        frameLayout = new FrameLayout(this);
        relativeLayout = new RelativeLayout(this);

        jumpButton.setId(R.id.jumpButtonId);
        jumpButton.setBackgroundResource(R.drawable.up_arrow_green);

        scoreText.setId(R.id.scoreTextId);
        scoreText.setText("0");
        scoreText.setTextSize(25);
        scoreText.setTextColor(Color.BLUE);
        
        coolDownText.setId(R.id.countDownTextId);
        coolDownText.setText("0");
        coolDownText.setTextSize(25);
        coolDownText.setTextColor(Color.BLUE);

        platformPlaceholder.setId(R.id.platformPlaceholderId);
        platformPlaceholder.setImageResource(R.drawable.platform_placeholder);
        
        platformIcon.setId(R.id.nexPlatformIconId);
        platformIcon.setImageResource(R.drawable.basicplatform);
        platformIcon.setVisibility(View.INVISIBLE);
        
        retryButton.setId(R.id.retryButtonId);
        retryButton.setBackgroundResource(R.drawable.reload_arrow);
        retryButton.setVisibility(View.INVISIBLE);

        bestScore.setId(R.id.bestScoreId);
        bestScore.setText("Personal best: " + 0);
        bestScore.setTextSize(22);
        bestScore.setTextColor(Color.MAGENTA);
        bestScore.setVisibility(View.INVISIBLE);

        RelativeLayout.LayoutParams buttonParams = new RelativeLayout.LayoutParams(230, 230);
        RelativeLayout.LayoutParams scoreTextParams = new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        RelativeLayout.LayoutParams coolDownTextParams = new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        RelativeLayout.LayoutParams platformPlaceholderParams = new RelativeLayout.LayoutParams(155, 155);
        RelativeLayout.LayoutParams platformIconParams = new RelativeLayout.LayoutParams(115, 115);
        RelativeLayout.LayoutParams retryButtonParams = new RelativeLayout.LayoutParams(250, 250);
        RelativeLayout.LayoutParams bestScoreParams = new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        RelativeLayout.LayoutParams layoutParams = new RelativeLayout.LayoutParams(RelativeLayout.LayoutParams.MATCH_PARENT, RelativeLayout.LayoutParams.MATCH_PARENT);

        relativeLayout.setLayoutParams(layoutParams);
        relativeLayout.addView(jumpButton);
        relativeLayout.addView(scoreText);
        relativeLayout.addView(platformIcon);
        relativeLayout.addView(platformPlaceholder);
        relativeLayout.addView(coolDownText);
        relativeLayout.addView(retryButton);
        relativeLayout.addView(bestScore);

        buttonParams.addRule(RelativeLayout.ALIGN_PARENT_LEFT);
        buttonParams.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
        buttonParams.setMargins(30, 0, 0, 30);
        jumpButton.setLayoutParams(buttonParams);

        scoreTextParams.addRule(RelativeLayout.ALIGN_PARENT_RIGHT);
        scoreTextParams.addRule(RelativeLayout.ALIGN_PARENT_TOP);
        scoreTextParams.setMargins(0, 30, 10, 0);
        scoreText.setLayoutParams(scoreTextParams);

        platformPlaceholderParams.addRule(RelativeLayout.CENTER_HORIZONTAL);
        platformPlaceholderParams.addRule(RelativeLayout.ALIGN_PARENT_TOP);
        platformPlaceholderParams.setMargins(0, 15, 0, 0);
        platformPlaceholder.setLayoutParams(platformPlaceholderParams);

        coolDownTextParams.addRule(RelativeLayout.CENTER_HORIZONTAL);
        coolDownTextParams.addRule(RelativeLayout.ALIGN_PARENT_TOP);
        coolDownTextParams.addRule(RelativeLayout.RIGHT_OF, R.id.platformPlaceholderId);
        coolDownTextParams.addRule(RelativeLayout.CENTER_VERTICAL, R.id.platformPlaceholderId);
        coolDownTextParams.setMargins(20, 30, 0, 0);
        coolDownText.setLayoutParams(coolDownTextParams);

        platformIconParams.addRule(RelativeLayout.CENTER_HORIZONTAL);
        platformIconParams.addRule(RelativeLayout.ALIGN_PARENT_TOP);
        platformIconParams.setMargins(0, 30, 0, 0);
        platformIcon.setLayoutParams(platformIconParams);

        retryButtonParams.addRule(RelativeLayout.CENTER_HORIZONTAL);
        retryButtonParams.addRule(RelativeLayout.CENTER_VERTICAL);
        retryButton.setLayoutParams(retryButtonParams);

        bestScoreParams.addRule(RelativeLayout.CENTER_HORIZONTAL);
        bestScoreParams.addRule(RelativeLayout.BELOW, R.id.retryButtonId);
        bestScoreParams.setMargins(0, 20, 0, 0);
        bestScore.setLayoutParams(bestScoreParams);

        frameLayout.addView(gameManager);
        frameLayout.addView(relativeLayout);
    }
}
