package com.example.checkbox;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.Toast;

public class MainActivity extends Activity {
	Button bt;
	CheckBox cb1;
	CheckBox cb2;
	CheckBox cb3;
	CheckBox cb4;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        bt = (Button) findViewById(R.id.button1);
        cb1 = (CheckBox) findViewById(R.id.checkBox1);
        cb2 = (CheckBox) findViewById(R.id.checkBox2);
        cb3 = (CheckBox) findViewById(R.id.checkBox3);
        cb4 = (CheckBox) findViewById(R.id.checkBox4);
        
        bt.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				
				StringBuffer sb = new StringBuffer();
				
				sb.append("PHP: ").append(cb1.isChecked());
				sb.append("\nJava: ").append(cb2.isChecked());
				sb.append("\nAndroid: ").append(cb3.isChecked());
				sb.append("\nShell: ").append(cb4.isChecked());
				
				Toast.makeText(MainActivity.this, sb.toString(), Toast.LENGTH_LONG).show();
			}
		});
    }
    
}
