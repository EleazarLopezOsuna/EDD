package com.example.user.edd;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import java.util.ArrayList;
import java.util.List;

public class Nuevo extends AppCompatActivity {

    private RequestQueue queue;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_nuevo);
        addListenerOnButton();
        addListenerOnSpinnerItemSelection();
        llenar();
    }

    private void llenar(){
        Spinner salida = findViewById(R.id.salida);
        List<String> list = buscarPaises();
        ArrayAdapter<String> dataAdapter = new ArrayAdapter<String>(this,android.R.layout.simple_spinner_item, list);
        dataAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        salida.setAdapter(dataAdapter);
    }

    private List<String> buscarPaises(){
        queue = Volley.newRequestQueue(this);
        final List<String> list = new ArrayList<String>();
        String url = "http://192.168.0.11:8080/edd/webapi/Destinos/Recorrer";
        final StringRequest request = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                String base = response;
                String items[] = base.split(",");
                for (int i = 1; i < items.length; i++){
                    list.add(items[i]);
                }
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {

            }
        });
        queue.add(request);
        return list;
    }

    public void addListenerOnSpinnerItemSelection() {
        Spinner spinner1;
        spinner1 = (Spinner) findViewById(R.id.salida);
        spinner1.setOnItemSelectedListener(new CustomOnItemSelectedListener());
    }

    public void addListenerOnButton() {
        Spinner spinner1;
        spinner1 = (Spinner) findViewById(R.id.salida);
    }

    private class CustomOnItemSelectedListener implements android.widget.AdapterView.OnItemSelectedListener {
        public void onItemSelected(AdapterView<?> parent, View view, int pos, long id) {
            Toast.makeText(parent.getContext(),
                    "OnItemSelectedListener : " + parent.getItemAtPosition(pos).toString(),
                    Toast.LENGTH_SHORT).show();
        }

        @Override
        public void onNothingSelected(AdapterView<?> arg0) {
            // TODO Auto-generated method stub
        }
    }
}
