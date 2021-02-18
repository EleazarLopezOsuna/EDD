package com.example.user.edd;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import org.json.JSONException;

public class Main extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button butt = findViewById(R.id.button4);
        butt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                    Intent NuevoClass = new Intent(getApplicationContext(), Nuevo.class);
                    startActivity(NuevoClass);
            }
        });
        Button butt1 = findViewById(R.id.button3);
        butt1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                    Intent Viajes = new Intent(getApplicationContext(), Viajes.class);
                    startActivity(Viajes);
            }
        });
    }
}
