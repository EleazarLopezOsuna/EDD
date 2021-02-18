package com.example.user.edd;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

public class Main extends AppCompatActivity {

    String nombre;
    String codigo;
    private RequestQueue queue;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button butt = findViewById(R.id.button4);
        Bundle miBundleRuta = this.getIntent().getExtras();
        nombre = miBundleRuta.getString("nombre");
        codigo = miBundleRuta.getString("codigo");
        butt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                    Intent NuevoClass = new Intent(getApplicationContext(), Nuevo.class);
                    Bundle miBundleRuta = new Bundle();
                    miBundleRuta.putString("nombre", nombre);
                    miBundleRuta.putString("codigo", codigo);
                    NuevoClass.putExtras(miBundleRuta);
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
        Button butt2 = findViewById(R.id.button8);
        butt2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                EditText pais1 = findViewById(R.id.editText3);
                String tpais1 = pais1.getText().toString();
                eliminar(tpais1);
            }
        });
    }

    public void eliminar(String nombre){
        queue = Volley.newRequestQueue(this);
        String url = "http://192.168.43.197:8080/edd/webapi/Vuelos/Eliminar/" + nombre;
        StringRequest request = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {

            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(Main.this, "", Toast.LENGTH_SHORT).show();
            }
        });
        queue.add(request);
    }
}
