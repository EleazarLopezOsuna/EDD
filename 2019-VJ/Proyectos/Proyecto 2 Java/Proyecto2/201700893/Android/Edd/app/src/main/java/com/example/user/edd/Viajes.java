package com.example.user.edd;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Base64;
import android.widget.ImageView;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

public class Viajes extends AppCompatActivity {

    private RequestQueue queue;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_viajes);
        generarImagen();
        Imagen();
    }

    private void Imagen(){
        queue = Volley.newRequestQueue(this);
        String url = "http://192.168.43.197:8080/edd/webapi/Imagenes/Tabla";
        StringRequest request = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                ImageView imagen = findViewById(R.id.imageView);
                byte[] decodedString = Base64.decode(response, Base64.DEFAULT);
                Bitmap decodedByte = BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
                imagen.setImageBitmap(decodedByte);
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(Viajes.this, "", Toast.LENGTH_SHORT).show();
            }
        });
        queue.add(request);
    }

    private void generarImagen(){
        queue = Volley.newRequestQueue(this);
        String url = "http://192.168.43.197:8080/edd/webapi/Vuelos/Recorrer";
        StringRequest request = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                Toast.makeText(Viajes.this, "", Toast.LENGTH_SHORT).show();
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(Viajes.this, "", Toast.LENGTH_SHORT).show();
            }
        });
        queue.add(request);
    }
}
