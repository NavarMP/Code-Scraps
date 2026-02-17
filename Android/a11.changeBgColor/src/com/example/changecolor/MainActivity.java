package com.example.changecolor;

import android.os.Bundle;
import android.app.Activity;
import android.graphics.Color;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.RelativeLayout;

public class MainActivity extends Activity {
	Button b1;
	RelativeLayout rel;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        b1 = (Button) findViewById(R.id.button1);
        
        rel = (RelativeLayout) findViewById(R.id.r1);
        rel.setBackgroundColor(Color.CYAN);
        b1.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				rel.setBackgroundColor(Color.MAGENTA);
			}
		});
    }
}
