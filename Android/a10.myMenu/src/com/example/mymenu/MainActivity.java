package com.example.mymenu;

import android.R.menu;
import android.net.Uri;
import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
    	menu.add(0, 0, 0, "Open"); //group ID, item ID, sort order, title
    	menu.add(0, 1, 1, "Save");
    	menu.add(0, 2, 2, "Google");
    	menu.add(0, 3, 3, "Settings");
        getMenuInflater().inflate(R.menu.main, menu);
        
        return true;
    }
    
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
    	// TODO Auto-generated method stub
//    	int id = item.getItemId();
//    	switch (id) {
//		case R.id.action_open:
//			Toast.makeText(getApplicationContext(), "File didn't Open",
//					Toast.LENGTH_LONG).show();
//			break;
//		case R.id.action_save:
//			
//			Toast.makeText(getApplicationContext(), "File didn't Save",
//					Toast.LENGTH_LONG).show();
//			break;
//		case R.id.action_google:
//			Intent i = new Intent(Intent.ACTION_VIEW);
//			i.setData(Uri.parse("https://google.com/"));
//			startActivity(i);
//			break;
//		default:
//			break;
//		}
//    	return super.onOptionsItemSelected(item);
    	return false;
    }
}
