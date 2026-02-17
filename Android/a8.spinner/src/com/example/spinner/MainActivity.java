package com.example.spinner;

//import android.R.string;
import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.TextView;

public class MainActivity extends Activity implements OnItemSelectedListener {
	Spinner sp;
	TextView tv;
	String [] items = {"Computer_Network", "Android_Programming", "System_Software", "Operating_System"};
    
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        sp = (Spinner) findViewById(R.id.spinner1);
        tv = (TextView) findViewById(R.id.textView1);
        ArrayAdapter<String> ad = new ArrayAdapter<String>
        (this, android.R.layout.simple_list_item_1, items);
        	sp.setAdapter(ad);
        	sp.setOnItemSelectedListener(this);
    }

	@Override
	public void onItemSelected(AdapterView<?> arg0, View arg1, int arg2,
			long arg3) {
		// TODO Auto-generated method stub
		tv.setText(items[arg2]);		
	}

	@Override
	public void onNothingSelected(AdapterView<?> arg0) {
		// TODO Auto-generated method stub
	}
}
