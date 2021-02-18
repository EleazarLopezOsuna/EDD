package com.example.user.edd;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.format.Time;
import android.util.Base64;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import java.io.InputStream;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Locale;
import java.util.Random;

public class Reservacion extends AppCompatActivity {

    TextView msj;
    String codigos;
    String extras;
    String nombre;
    String rutas;
    String codx;

    private RequestQueue queue;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_reservacion);

        msj = findViewById(R.id.textView);
        Bundle miBundleRuta = this.getIntent().getExtras();
        codigos = miBundleRuta.getString("codigos");
        extras = miBundleRuta.getString("costotiempo");
        nombre = miBundleRuta.getString("nombre");
        codx = miBundleRuta.getString("codigo");
        rutas = miBundleRuta.getString("paises");
        String datos[] = extras.split(",");
        String mostrar = "Costo: " + datos[0] + " Tiempo: " + datos[1];
        msj.setText("Ruta: " + rutas + " " + mostrar);

        generarImagen();

        Imagen();

        Button butt = findViewById(R.id.cancelar);
        butt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });

        Button butt1 = findViewById(R.id.reservar);
        butt1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                vuelo();
            }
        });
    }

    private void Imagen(){
        queue = Volley.newRequestQueue(this);
        String url = "http://192.168.43.197:8080/edd/webapi/Imagenes/Grafo";
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
                Toast.makeText(Reservacion.this, "", Toast.LENGTH_SHORT).show();
            }
        });
        queue.add(request);
    }

    private void generarImagen(){
        queue = Volley.newRequestQueue(this);
        String datos[] = extras.split(",");
        String url = "http://192.168.43.197:8080/edd/webapi/Rutas/Recorrerr";
        StringRequest request = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                Toast.makeText(Reservacion.this, "", Toast.LENGTH_SHORT).show();
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(Reservacion.this, "", Toast.LENGTH_SHORT).show();
            }
        });
        queue.add(request);
    }

    private void vuelo(){
        queue = Volley.newRequestQueue(this);
        String datos[] = extras.split(",");
        String url = "http://192.168.43.197:8080/edd/webapi/Vuelos/InsertarT/" + codx + "/" + nombre + "/" + datos[0] + "/" + datos[1] + "/" + rutas;
        Toast.makeText(Reservacion.this, url, Toast.LENGTH_SHORT).show();
        StringRequest request = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                Toast.makeText(Reservacion.this, "", Toast.LENGTH_SHORT).show();
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(Reservacion.this, "", Toast.LENGTH_SHORT).show();
            }
        });
        queue.add(request);
    }
}
