# Android Lab Programs

This document contains 15 practical Android programs, including their aims, XML layouts, Java code, and simulated outputs.

---

## 1. Hello World Program
**Aim:** Write a program to Toast "Hello World".

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_centerHorizontal="true"
        android:layout_marginLeft="52dp"
        android:layout_marginTop="61dp"
        android:text="SHOW TOAST" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.andoubleos.myprogram;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn = (Button) findViewById(R.id.button1);
        btn.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View arg0) {
                Toast.makeText(MainActivity.this, "Hello World", Toast.LENGTH_LONG).show();
            }
        });
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
|                                |
|                                |
|                                |
|                                |
|                                |
|         [ SHOW TOAST ]         |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
+--------------------------------+

[ Action ]
User clicks the "SHOW TOAST" button.

[ Output ]
A popup toast appears at the bottom of the screen: "Hello World"
```

---

## 2. Addition of Two Numbers
**Aim:** Write a program to add two numbers.

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <TextView
        android:id="@+id/textView1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentLeft="true"
        android:layout_marginLeft="20dp"
        android:layout_marginTop="43dp"
        android:text="Enter First No" />

    <EditText
        android:id="@+id/editText1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignBottom="@+id/textView1"
        android:layout_toRightOf="@+id/textView1"
        android:ems="10"
        android:inputType="numberDecimal" />

    <TextView
        android:id="@+id/textView2"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentLeft="true"
        android:layout_below="@+id/textView1"
        android:layout_marginLeft="20dp"
        android:layout_marginTop="43dp"
        android:text="Enter Second No" />

    <EditText
        android:id="@+id/editText2"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignBottom="@+id/textView2"
        android:layout_toRightOf="@+id/textView2"
        android:ems="10"
        android:inputType="numberDecimal" />

    <TextView
        android:id="@+id/textView3"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignLeft="@+id/textView2"
        android:layout_below="@+id/textView2"
        android:layout_marginTop="47dp"
        android:text="" />

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentBottom="true"
        android:layout_centerHorizontal="true"
        android:layout_marginBottom="22dp"
        android:text="Show SUM" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.example.twosum;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {
    EditText firstNumber;
    EditText secondNumber;
    TextView addResult;
    Button btnAdd;
    double num1, num2, sum;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        firstNumber = (EditText) findViewById(R.id.editText1);
        secondNumber = (EditText) findViewById(R.id.editText2);
        addResult = (TextView) findViewById(R.id.textView3);
        btnAdd = (Button) findViewById(R.id.button1);

        btnAdd.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                num1 = Double.parseDouble(firstNumber.getText().toString());
                num2 = Double.parseDouble(secondNumber.getText().toString());
                sum = num1 + num2;
                addResult.setText(Double.toString(sum));
            }
        });
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
|                                |
| Enter First No                 |
| [ 15.5      ]                  |
|                                |
| Enter Second No                |
| [ 10.2      ]                  |
|                                |
| [ Result Output ]              |
|                                |
|                                |
|                                |
|          [ Show SUM ]          |
+--------------------------------+

[ Action ]
User inputs 15.5 in the first box and 10.2 in the second box, then clicks "Show SUM".

[ Output ]
The empty TextView gets updated with the sum: "25.7"
```

---

## 3. Fetch Data from an EditText and Display it in a TextView
**Aim:** Write a program to fetch data from an EditText and display it in a TextView by clicking a button.

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <TextView
        android:id="@+id/textView1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentLeft="true"
        android:layout_alignParentTop="true"
        android:layout_marginLeft="39dp"
        android:layout_marginTop="51dp"
        android:text="Enter any text here :"
        android:textAppearance="?android:attr/textAppearanceLarge" />

    <EditText
        android:id="@+id/editText1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignLeft="@+id/textView1"
        android:layout_below="@+id/textView1"
        android:layout_marginTop="44dp"
        android:ems="10" />

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignLeft="@+id/editText1"
        android:layout_centerVertical="true"
        android:layout_marginLeft="43dp"
        android:text="Show" />

    <TextView
        android:id="@+id/textView2"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignLeft="@+id/button1"
        android:layout_below="@+id/button1"
        android:layout_marginTop="69dp"
        android:text=""
        android:textAppearance="?android:attr/textAppearanceLarge" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.example.fetchtext;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {
    EditText e1;
    TextView t1;
    Button b1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        e1 = (EditText) findViewById(R.id.editText1);
        t1 = (TextView) findViewById(R.id.textView2);
        b1 = (Button) findViewById(R.id.button1);

        b1.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View arg0) {
                t1.setText(e1.getText().toString());
            }
        });
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
|                                |
| Enter any text here :          |
| [ Hello World!    ]   [ Show ] |
|                                |
|                                |
| [ Result Text ]                |
|                                |
|                                |
|                                |
|                                |
|                                |
+--------------------------------+

[ Action ]
User inputs "Hello World!" in the text field and clicks "Show".

[ Output ]
The empty TextView below the button displays: "Hello World!"
```

---

## 4. Multiplication Table
**Aim:** Write a program to display the multiplication table of a given number.

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <TextView
        android:id="@+id/textView1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Enter a Number :" />

    <EditText
        android:id="@+id/editText1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignLeft="@+id/textView1"
        android:layout_below="@+id/textView1"
        android:ems="10"
        android:inputType="number" />

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_below="@+id/editText1"
        android:layout_toRightOf="@+id/textView1"
        android:text="Show Table" />

    <TextView
        android:id="@+id/textView2"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignLeft="@+id/textView1"
        android:layout_below="@+id/button1"
        android:layout_marginTop="42dp"
        android:gravity="center"
        android:textSize="25sp" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.example.multplcntable;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {
    EditText e1;
    Button b1;
    TextView t1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        e1 = (EditText) findViewById(R.id.editText1);
        t1 = (TextView) findViewById(R.id.textView2);
        b1 = (Button) findViewById(R.id.button1);

        b1.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View arg0) {
                StringBuffer temp = new StringBuffer();
                String num = e1.getText().toString();
                int n = Integer.parseInt(num);

                for (int i = 1; i <= 10; i++) {
                    int ans = i * n;
                    temp.append(i + " x " + n + " = " + ans + "\n");
                }
                t1.setText(temp.toString());
            }
        });
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
| Enter a Number :               |
| [ 5    ]           [Show Table]|
|                                |
|           1 x 5 = 5            |
|           2 x 5 = 10           |
|           3 x 5 = 15           |
|           4 x 5 = 20           |
|           ...                  |
|          10 x 5 = 50           |
|                                |
|                                |
|                                |
+--------------------------------+

[ Action ]
User inputs "5" and clicks the "Show Table" button.

[ Output ]
The large TextView displays the multiplication table for 5.
```

---

## 5. Check Box
**Aim:** Write a program to check the items listed and display the selection status via Toast.

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <CheckBox
        android:id="@+id/checkBox1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentLeft="true"
        android:layout_alignParentTop="true"
        android:layout_marginLeft="46dp"
        android:layout_marginTop="40dp"
        android:text="Java"
        android:textSize="25sp" />

    <CheckBox
        android:id="@+id/checkBox2"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignLeft="@+id/checkBox1"
        android:layout_below="@+id/checkBox1"
        android:layout_marginTop="16dp"
        android:text="PHP"
        android:textSize="25sp" />

    <CheckBox
        android:id="@+id/checkBox3"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignLeft="@+id/checkBox2"
        android:layout_below="@+id/checkBox2"
        android:layout_marginTop="15dp"
        android:text="Android"
        android:textSize="25sp" />

    <CheckBox
        android:id="@+id/checkBox4"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignLeft="@+id/checkBox3"
        android:layout_below="@+id/checkBox3"
        android:layout_marginTop="14dp"
        android:text="Shell"
        android:textSize="25sp" />

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_below="@+id/checkBox4"
        android:layout_centerHorizontal="true"
        android:layout_marginTop="46dp"
        android:text="Submit" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.example.ckeckboxs;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.Toast;

public class MainActivity extends Activity {
    Button bt;
    CheckBox cb1, cb2, cb3, cb4;

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
                StringBuffer sb = new StringBuffer();
                sb.append("Java : ").append(cb1.isChecked());
                sb.append("\n PHP : ").append(cb2.isChecked());
                sb.append("\n Android :").append(cb3.isChecked());
                sb.append("\n Shell : ").append(cb4.isChecked());

                Toast.makeText(MainActivity.this, sb.toString(), Toast.LENGTH_LONG).show();
            }
        });
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
|                                |
|                                |
|  [x] Java                      |
|  [ ] PHP                       |
|  [x] Android                   |
|  [ ] Shell                     |
|                                |
|           [ Submit ]           |
|                                |
|                                |
|                                |
+--------------------------------+

[ Action ]
User checks "Java" and "Android", and leaves the rest unchecked, then clicks "Submit".

[ Output ]
A popup toast is displayed:
"Java : true
 PHP : false
 Android :true
 Shell : false"
```

---

## 6. Radio Button
**Aim:** Write a program to select gender or a category using radio buttons and show the selected text via Toast.

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <TextView
        android:id="@+id/textView1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentLeft="true"
        android:layout_alignParentTop="true"
        android:layout_marginLeft="34dp"
        android:layout_marginTop="28dp"
        android:text="Select Gender:"
        android:textAppearance="?android:attr/textAppearanceLarge" />

    <RadioGroup
        android:id="@+id/radioGroup1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentLeft="true"
        android:layout_below="@+id/textView1"
        android:layout_marginLeft="58dp"
        android:layout_marginTop="20dp">

        <RadioButton
            android:id="@+id/radio0"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Male" />

        <RadioButton
            android:id="@+id/radio1"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Female" />

        <RadioButton
            android:id="@+id/radio2"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Transgender" />

        <RadioButton
            android:id="@+id/radio3"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Other" />
    </RadioGroup>

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignRight="@+id/radioGroup1"
        android:layout_below="@+id/radioGroup1"
        android:layout_marginRight="21dp"
        android:layout_marginTop="60dp"
        android:text="Submit" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.example.gender;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

public class MainActivity extends Activity {
    Button btn;
    RadioGroup rg;
    RadioButton rb;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn = (Button) findViewById(R.id.button1);
        rg = (RadioGroup) findViewById(R.id.radioGroup1);

        btn.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View arg0) {
                int selected = rg.getCheckedRadioButtonId();
                if (selected != -1) {
                    rb = (RadioButton) findViewById(selected);
                    Toast.makeText(MainActivity.this, rb.getText(), Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
| Select Gender:                 |
|                                |
|  ( ) Male                      |
|  (o) Female                    |
|  ( ) Transgender               |
|  ( ) Other                     |
|                                |
|                      [ Submit ]|
|                                |
|                                |
|                                |
|                                |
+--------------------------------+

[ Action ]
User selects the "Female" radio button and clicks "Submit".

[ Output ]
A popup toast shows: "Female"
```

---

## 7. List View
**Aim:** Write a program to display the items in a ListView and handle item click events using a Toast.

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <ListView
        android:id="@+id/listView1"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_alignParentLeft="true"
        android:layout_alignParentTop="true">
    </ListView>

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.example.listv;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

public class MainActivity extends Activity implements OnItemClickListener {
    ListView lv;
    String title[] = {"Google", "FaceBook", "Twitter", "Youtube"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        try {
            lv = (ListView) findViewById(R.id.listView1);
            ArrayAdapter<String> adt = new ArrayAdapter<String>(
                    MainActivity.this,
                    android.R.layout.simple_list_item_1,
                    title
            );
            lv.setAdapter(adt);
            lv.setOnItemClickListener(this);
        } catch (Exception e) {
            Toast.makeText(this, e.toString(), Toast.LENGTH_SHORT).show();
        }
    }

    @Override
    public void onItemClick(AdapterView<?> arg0, View arg1, int position, long arg3) {
        Toast.makeText(this, title[position] + " is selected", Toast.LENGTH_LONG).show();
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
| Google                         |
|--------------------------------|
| FaceBook                       |
|--------------------------------|
| Twitter                        |
|--------------------------------|
| Youtube                        |
|--------------------------------|
|                                |
|                                |
|                                |
|                                |
|                                |
+--------------------------------+

[ Action ]
User taps on the "Twitter" item in the ListView.

[ Output ]
A popup toast is displayed: "Twitter is selected"
```

---

## 8. Spinner
**Aim:** Write a program to show items in a dropdown Spinners and display the selected item text below.

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <Spinner
        android:id="@+id/spinner1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentTop="true"
        android:layout_centerHorizontal="true"
        android:layout_marginTop="24dp" />

    <TextView
        android:id="@+id/textView1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentBottom="true"
        android:layout_centerHorizontal="true"
        android:layout_marginBottom="138dp"
        android:text=""
        android:textAppearance="?android:attr/textAppearanceLarge" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.example.spinner;

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
    String[] items = {"Computer_Network", "Android_Programming", "System_Software", "Operating-System"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        sp = (Spinner) findViewById(R.id.spinner1);
        tv = (TextView) findViewById(R.id.textView1);

        ArrayAdapter<String> ad = new ArrayAdapter<String>(
                this,
                android.R.layout.simple_spinner_dropdown_item,
                items
        );
        sp.setAdapter(ad);
        sp.setOnItemSelectedListener(this);
    }

    @Override
    public void onItemSelected(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
        tv.setText(items[arg2]);
    }

    @Override
    public void onNothingSelected(AdapterView<?> arg0) {
        // Do nothing
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
|                                |
|   [ Computer_Network     |v]   |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|       Computer_Network         |
|                                |
|                                |
+--------------------------------+

[ Action ]
User clicks the spinner, selects "Computer_Network".

[ Output ]
The text view below immediately updates to display: "Computer_Network"
```

---

## 9. Image View
**Aim:** Write a program to display images from local resources in an ImageView and switch them using buttons.

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <ImageView
        android:id="@+id/imageView1"
        android:layout_width="300dp"
        android:layout_height="300dp"
        android:layout_marginTop="14dp"
        android:layout_marginLeft="20dp" />

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentBottom="true"
        android:layout_alignParentLeft="true"
        android:layout_marginBottom="51dp"
        android:layout_marginLeft="22dp"
        android:text="IMAGE 1" />

    <Button
        android:id="@+id/button2"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignBaseline="@+id/button1"
        android:layout_alignBottom="@+id/button1"
        android:layout_toRightOf="@+id/button1"
        android:text="IMAGE 2" />

    <Button
        android:id="@+id/button3"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignBottom="@+id/button2"
        android:layout_toRightOf="@+id/button2"
        android:text="IMAGE 3" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.example.imgview;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends Activity implements OnClickListener {
    Button b1, b2, b3;
    ImageView img;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        b1 = (Button) findViewById(R.id.button1);
        b2 = (Button) findViewById(R.id.button2);
        b3 = (Button) findViewById(R.id.button3);
        img = (ImageView) findViewById(R.id.imageView1);

        b1.setOnClickListener(this);
        b2.setOnClickListener(this);
        b3.setOnClickListener(this);
    }

    @Override
    public void onClick(View arg0) {
        switch (arg0.getId()) {
            case R.id.button1:
                img.setBackgroundResource(R.drawable.image1);
                break;
            case R.id.button2:
                img.setBackgroundResource(R.drawable.image2);
                break;
            case R.id.button3:
                img.setBackgroundResource(R.drawable.image3);
                break;
            default:
                break;
        }
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
|                                |
|      +------------------+      |
|      |                  |      |
|      |      IMAGE       |      |
|      |                  |      |
|      |                  |      |
|      +------------------+      |
|                                |
|                                |
|                                |
| [IMAGE 1] [IMAGE 2] [IMAGE 3]  |
+--------------------------------+

[ Action ]
User taps the "IMAGE 2" button.

[ Output ]
The large ImageView directly updates visually to display `R.drawable.image2` loaded from the local application assets.
```

---

## 10. Menu Program
**Aim:** Write a program to create an options menu with three menu items.

### Main.Xml File (`res/menu/main.xml`)
```xml
<menu xmlns:android="http://schemas.android.com/apk/res/android">
    <item
        android:id="@+id/action_settings"
        android:orderInCategory="100"
        android:showAsAction="never"
        android:title="Settings" />
    <item
        android:id="@+id/action_item1"
        android:orderInCategory="100"
        android:showAsAction="never"
        android:title="Open File" />
    <item
        android:id="@+id/action_item2"
        android:orderInCategory="100"
        android:showAsAction="never"
        android:title="Save File" />
    <item
        android:id="@+id/action_item3"
        android:orderInCategory="100"
        android:showAsAction="never"
        android:title="Open Google Safari" />
</menu>
```

### Layout.Xml File (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <TextView
        android:id="@+id/textView1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Press the top right to open the menu" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.example.menu;

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
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();
        switch (id) {
            case R.id.action_item1:
                Toast.makeText(getApplicationContext(), "File Opened", Toast.LENGTH_LONG).show();
                break;
            case R.id.action_item2:
                Toast.makeText(getApplicationContext(), "File Saved", Toast.LENGTH_LONG).show();
                break;
            case R.id.action_item3:
                Intent i = new Intent(Intent.ACTION_VIEW);
                i.setData(Uri.parse("http://www.google.com"));
                startActivity(i);
                break;
        }
        return super.onOptionsItemSelected(item);
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
| Press the top right to open    |
| the menu                  [ ⋮ ]|
|                           +--+ |
|                           |  | |
|         +-----------------|  | |
|         | Settings        +--+ |
|         | Open File          | |
|         | Save File          | |
|         | Open Google Safari | |
|         +--------------------+ |
|                                |
|                                |
+--------------------------------+

[ Action ]
User clicks the three dots icon [ ⋮ ] on the top right action bar. A dropdown displays settings/options. User taps "Open Google Safari".

[ Output ]
The Android system handles the intent and redirects the user into their default web browser to: `http://www.google.com`.
```

---

## 11. Change the Background Colour of the Activity
**Aim:** Write a program to change the Background colour of the Activity.

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:id="@+id/r1"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_centerHorizontal="true"
        android:layout_centerVertical="true"
        android:text="CHANGE COLOR" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.gems.pqr;

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
        
        // Default color setup
        rel.setBackgroundColor(Color.CYAN);
        
        b1.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View arg0) {
                rel.setBackgroundColor(Color.MAGENTA);
            }
        });
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
| ~ ~ ~ ~ ~ CYAN BG ~ ~ ~ ~ ~ ~  |
| ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  |
| ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  |
| ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  |
| ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  |
| ~ ~ ~ ~[ CHANGE COLOR ] ~ ~ ~  |
| ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  |
| ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  |
| ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  |
| ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  |
+--------------------------------+

[ Action ]
User clicks the "CHANGE COLOR" button.

[ Output ]
The entire layout's background color immediately switches from `CYAN` to `MAGENTA` color.
```

---

## 12. Start Another Activity using Intent
**Aim:** Write a program to start another activity from your own activity using the intent mechanism.

### First XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:background="#0000ff"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <TextView
        android:id="@+id/textView1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentTop="true"
        android:layout_marginTop="30dp"
        android:text="Now you are in firstpage"
        android:textAppearance="?android:attr/textAppearanceLarge" />

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_below="@+id/textView1"
        android:layout_centerHorizontal="true"
        android:layout_marginTop="36dp"
        android:text="Go to next page" />

</RelativeLayout>
```

### Second XML Layout (`activity_second.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:background="#ff0000"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".SecondActivity">

    <TextView
        android:id="@+id/textView1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentLeft="true"
        android:layout_alignParentTop="true"
        android:layout_marginLeft="46dp"
        android:layout_marginTop="59dp"
        android:text="Now you are in secondpage"
        android:textAppearance="?android:attr/textAppearanceLarge" />

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignLeft="@+id/textView1"
        android:layout_below="@+id/textView1"
        android:layout_marginTop="52dp"
        android:text="Go to previous Activity" />

</RelativeLayout>
```

### First Java Code (`MainActivity.java`)
```java
package com.andoubleos.usingintent;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener {
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn = (Button) findViewById(R.id.button1);
        btn.setOnClickListener(this);
    }

    @Override
    public void onClick(View arg0) {
        Intent i = new Intent(MainActivity.this, SecondActivity.class);
        startActivity(i);
    }
}
```

### Second Java Code (`SecondActivity.java`)
```java
package com.andoubleos.usingintent;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class SecondActivity extends Activity implements OnClickListener {
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        btn = (Button) findViewById(R.id.button1);
        btn.setOnClickListener(this);
    }

    @Override
    public void onClick(View arg0) {
        Intent i = new Intent(SecondActivity.this, MainActivity.class);
        startActivity(i);
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
| Now you are in firstpage       |
|                                |
|       [ Go to next page ]      |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
+--------------------------------+

[ Action ]
User clicks "Go to next page".

[ Output ]
The screen flawlessly navigates (via Intent) to the second activity window displaying:
"Now you are in secondpage"
"[ Go to previous Activity ]"
```

---

## 13. Alert Box
**Aim:** Write a program to display an alert box with 'OK' and 'Cancel' options.

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentTop="true"
        android:layout_centerHorizontal="true"
        android:layout_marginTop="156dp"
        android:text="Show Alert" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.example.alertdialog;

import android.os.Bundle;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener {
    Button bt1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        bt1 = (Button) findViewById(R.id.button1);
        bt1.setOnClickListener(this);
    }

    public void onClick(View arg0) {
        AlertDialog.Builder b1 = new AlertDialog.Builder(MainActivity.this);
        b1.setIcon(R.drawable.ic_launcher);
        b1.setTitle("Caution!");
        b1.setMessage("Do you want to Quit?");

        b1.setPositiveButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface arg0, int arg1) {
                Toast.makeText(MainActivity.this, "You Clicked Ok", Toast.LENGTH_LONG).show();
            }
        });

        b1.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface arg0, int arg1) {
                Toast.makeText(MainActivity.this, "You Clicked Cancel", Toast.LENGTH_LONG).show();
            }
        });

        AlertDialog d1 = b1.create();
        d1.show();
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
|                                |
|                                |
|         [ Show Alert ]         |
|                                |
|    +-----------------------+   |
|    | Caution!              |   |
|    | Do you want to Quit?  |   |
|    |                       |   |
|    |     [CANCEL]   [OK]   |   |
|    +-----------------------+   |
|                                |
|                                |
+--------------------------------+

[ Action ]
User clicks "Show Alert". A native alert dialog pops up on the screen.

[ Output ]
If user clicks OK: A Toast displays "You Clicked Ok"
If user clicks Cancel: A Toast displays "You Clicked Cancel"
The dialog closes automatically.
```

---

## 14. Change the Background Image
**Aim:** Write a program to change the Background image randomly dynamically using an array of image resources.

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:id="@+id/rView"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentBottom="true"
        android:layout_centerHorizontal="true"
        android:layout_marginBottom="47dp"
        android:text="CHANGE" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.andoubleos.background;

import java.util.Random;
import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity {
    Button btn;
    View screenView;
    int[] images;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn = (Button) findViewById(R.id.button1);
        screenView = findViewById(R.id.rView);

        images = new int[] { R.drawable.image1, R.drawable.image2, R.drawable.image3, R.drawable.image4, R.drawable.image6 };
        
        btn.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View arg0) {
                int aryLength = images.length;
                Random rand = new Random();
                int randNum = rand.nextInt(aryLength);
                screenView.setBackgroundResource(images[randNum]);
            }
        });
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
|          +---------+           |
|          |         |           |
|          |  IMAGE  |           |
|          |         |           |
|          +---------+           |
|                                |
|                                |
|                                |
|                                |
|                                |
|           [ CHANGE ]           |
|                                |
+--------------------------------+

[ Action ]
User clicks the "CHANGE" button.

[ Output ]
The Android system generates a random numeric index and updates the parent relative layout background mapping to `R.drawable.image<#>` matching the random selection.
```

---

## 15. Display Date and Time using Dialog Box
**Aim:** Write a program to display the current system Date and Time inside an AlertDialog Box when a button is pressed.

### XML Layout (`activity_main.xml`)
```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context=".MainActivity">

    <Button
        android:id="@+id/button1"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_alignParentLeft="true"
        android:layout_alignParentTop="true"
        android:layout_marginLeft="104dp"
        android:layout_marginTop="154dp"
        android:text="Display Date" />

</RelativeLayout>
```

### Java Code (`MainActivity.java`)
```java
package com.example.timeanddate;

import java.util.Calendar;
import android.os.Bundle;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity {
    Button bt;
    int year, month, day, hr, min, sec;
    String sysdate, systime;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        bt = (Button) findViewById(R.id.button1);
        bt.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View arg0) {
                Calendar cal = Calendar.getInstance();
                year = cal.get(Calendar.YEAR);
                month = cal.get(Calendar.MONTH);
                day = cal.get(Calendar.DAY_OF_MONTH);
                hr = cal.get(Calendar.HOUR);
                min = cal.get(Calendar.MINUTE);
                sec = cal.get(Calendar.SECOND);

                sysdate = day + "/" + (month + 1) + "/" + year;
                systime = hr + ":" + min + ":" + sec;

                AlertDialog.Builder b1 = new AlertDialog.Builder(MainActivity.this);
                b1.setTitle("Date&Time");
                b1.setMessage("Current System Date is " + sysdate + "\nTime: " + systime);
                b1.setPositiveButton("OK", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface arg0, int arg1) {
                        // Do nothing on OK click
                    }
                });

                AlertDialog d = b1.create();
                d.show();
            }
        });
    }
}
```

### 📱 Simulated Output
```text
+--------------------------------+
|                                |
|                                |
|                                |
|                                |
|         [ Display Date ]       |
|                                |
|    +-----------------------+   |
|    | Date&Time             |   |
|    | Current System Date is|   |
|    | 4/3/2026              |   |
|    | Time: 17:39:35        |   |
|    |                 [OK]  |   |
|    +-----------------------+   |
+--------------------------------+

[ Action ]
User clicks "Display Date". The app queries `Calendar.getInstance()`.

[ Output ]
Dialog popup correctly reflects the native system clock. User clicks "OK" to dismiss it.
```
