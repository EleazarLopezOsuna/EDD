package com.example.user.edd;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.android.volley.AuthFailureError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Map;

public class Login extends AppCompatActivity {

    private RequestQueue queue;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        Button butt = findViewById(R.id.button);
        butt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    ingresar();
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            }
        });
    }

    private void ingresar() throws JSONException {
        queue = Volley.newRequestQueue(this);
        final EditText ide = findViewById(R.id.identificador);
        final EditText nom = findViewById(R.id.nombre);
        String id = ide.getText().toString();
        String no = nom.getText().toString();
        String url = "http://192.168.0.11:8080/edd/webapi/Login/IngresarA/" + id + "/" + no;
        final StringRequest request = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                String base = response;
                if(base.equals("true")){
                    Intent MainClass = new Intent(getApplicationContext(), Main.class);
                    startActivity(MainClass);
                }else{
                    Toast.makeText(Login.this, "ERROR", Toast.LENGTH_SHORT).show();
                    ide.setText("");
                    nom.setText("");
                }
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(Login.this, "ERROR", Toast.LENGTH_SHORT).show();
                ide.setText("");
                nom.setText("");
            }
        });
        queue.add(request);
    }

    private void estoEsGetConString(){
        String url = "http://192.168.0.11:8080/edd/webapi/Login/Ingresar";
        final StringRequest request = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                String base = response;
                Toast.makeText(Login.this, base, Toast.LENGTH_SHORT).show();
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {

            }
        });
        queue.add(request);
    }

}
