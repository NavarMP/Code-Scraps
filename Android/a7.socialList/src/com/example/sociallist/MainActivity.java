package com.example.sociallist;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

public class MainActivity extends Activity implements OnItemClickListener {
	ListView sl;
	String title[] = {"Youtube", "X", "Instagram", "Facebook"};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        try {
        	sl = (ListView) findViewById(R.id.listView1);
        	ArrayAdapter<String> adt = new ArrayAdapter<String>(MainActivity.this, android.R.layout.simple_list_item_1, title);
        	sl.setAdapter(adt);
        	sl.setOnItemClickListener(this);
        } catch (Exception e) {
        	Toast.makeText(this, e.toString(), Toast.LENGTH_SHORT).show();
        }
    }
    
	@Override
	public void onItemClick(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
		// TODO Auto-generated method stub
		Toast.makeText(this, title[arg2] + " is selected", Toast.LENGTH_LONG).show();
	};
};