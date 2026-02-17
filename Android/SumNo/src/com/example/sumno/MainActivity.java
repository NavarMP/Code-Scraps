package com.example.sumno;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {
	
	EditText firstNo;
	EditText secondNo;
	TextView result;
	Button sumBtn;
	double no1, no2, sum;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        firstNo = (EditText) findViewById(R.id.editText1);
        secondNo = (EditText) findViewById(R.id.editText2);
        result = (TextView) findViewById(R.id.textView3);
        sumBtn = (Button) findViewById(R.id.button1);
        
        sumBtn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				no1 = Double.parseDouble(firstNo.getText().toString());
				
				no2 = Double.parseDouble(secondNo.getText().toString());
				
				sum = no1 + no2;
				result.setText(Double.toString(sum));
			}
		});
    }
}
