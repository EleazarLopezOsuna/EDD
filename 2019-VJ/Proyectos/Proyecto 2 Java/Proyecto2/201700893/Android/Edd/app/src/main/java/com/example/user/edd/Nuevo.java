package com.example.user.edd;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import java.util.ArrayList;

public class Nuevo extends AppCompatActivity {

    private RequestQueue queue;
    private String scod1 = "";
    private String scod2 = "";
    static String a[] = {"",""};
    String nombre;
    String codx;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_nuevo);
        Bundle miBundleRuta = this.getIntent().getExtras();
        nombre = miBundleRuta.getString("nombre");
        codx = miBundleRuta.getString("codigo");
        Button butt = findViewById(R.id.button5);
        Button costo = findViewById(R.id.button6);
        Button tiempo = findViewById(R.id.button7);
        costo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ruta();
                rutaCorta(scod1, scod2, 1);
            }
        });
        tiempo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ruta();
                rutaCorta(scod1, scod2, 0);
            }
        });
        butt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ruta();
                buscarRuta(scod1, scod2);
            }
        });
    }

    private void ruta () {
        EditText pais1 = findViewById(R.id.editText);
        EditText pais2 = findViewById(R.id.editText2);
        String tpais1 = pais1.getText().toString();
        String tpais2 = pais2.getText().toString();
        buscarPais(tpais1,1);
        buscarPais(tpais2,2);
        scod1 = a[0];
        scod2 = a[1];
    }

    private void buscarPais(String pais, final int op){
        queue = Volley.newRequestQueue(this);
        String url = "http://192.168.43.197:8080/edd/webapi/Destinos/Nombre/" + pais;
        StringRequest request = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                String base = response;
                switch (op){
                    case 1:
                        a[0] = base;
                        break;
                    case 2:
                        a[1] = base;
                        break;
                }
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(Nuevo.this, "ERROR", Toast.LENGTH_SHORT).show();
            }
        });
        queue.add(request);
    }

    private void rutaCorta(String cod1, String cod2, int tipo){
        queue = Volley.newRequestQueue(this);
        String url = "http://192.168.43.197:8080/edd/webapi/Rutas/BuscarRutaCorta/" + cod1 + "/" + cod2 + "/" +  tipo;
        Toast.makeText(Nuevo.this, url, Toast.LENGTH_SHORT).show();
        StringRequest request = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                String base = response;
                vuelo(base);
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(Nuevo.this, "", Toast.LENGTH_SHORT).show();
            }
        });
        queue.add(request);
    }

    private void vuelo(String d){
        queue = Volley.newRequestQueue(this);
        String url = "http://192.168.43.197:8080/edd/webapi/Vuelos/InsertarT/" + codx + "/" + nombre + "/0/0/" + d;
        StringRequest request = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                Toast.makeText(Nuevo.this, "", Toast.LENGTH_SHORT).show();
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(Nuevo.this, "", Toast.LENGTH_SHORT).show();
            }
        });
        queue.add(request);
    }

    private void buscarRuta(String cod1, String cod2){
        queue = Volley.newRequestQueue(this);
        String url = "http://192.168.43.197:8080/edd/webapi/Rutas/ObtenerRutas/1/" + cod1 + "/" + cod2 + "/0";
        StringRequest request = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                String base = response;
                String datos[] = base.split(";");
                ArrayList<String> elementos = new ArrayList<>();
                for(int i = 0; i < datos.length; i++){
                    elementos.add(datos[i]);
                }
                ListView lista = findViewById(R.id.list_item);
                ArrayAdapter adaptador = new ArrayAdapter(Nuevo.this, android.R.layout.simple_list_item_1, elementos);
                lista.setAdapter(adaptador);
                lista.setOnItemClickListener(new AdapterView.OnItemClickListener() {
                    @Override
                    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                        String datos[] = parent.getItemAtPosition(position).toString().split("-"); // Se separan campos
                        String codigo = "";
                        String ruta = "";


                        String extra[] = datos[1].split(",");
                        String coti = extra[0] + "," + extra[1];

                        String paises[] = datos[0].split(",");
                        for(int i = 0; i < paises.length; i++){
                            String da[] = paises[i].split(":");
                            if(i == (paises.length - 1)){
                                ruta += da[0];
                                codigo += da[1];
                            }else{
                                ruta += da[0] + ",";
                                codigo += da[1] + ",";
                            }
                        }

                        Intent intent = new Intent(Nuevo.this, Reservacion.class);
                        Bundle miBundleRuta = new Bundle();
                        miBundleRuta.putString("codigo", codx);
                        miBundleRuta.putString("nombre", nombre);
                        miBundleRuta.putString("costotiempo", coti);
                        miBundleRuta.putString("paises", ruta);
                        intent.putExtras(miBundleRuta);
                        startActivity(intent);
                    }
                });
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(Nuevo.this, "", Toast.LENGTH_SHORT).show();
            }
        });
        queue.add(request);
    }
}
