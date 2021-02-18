package com.example.user.edd;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class Login extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        Button butt = findViewById(R.id.button);
        butt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                    ingresar();
            }
        });
    }

    private void ingresar(){
        final EditText ide = findViewById(R.id.identificador);
        final EditText nom = findViewById(R.id.nombre);
        Intent MainClass = new Intent(getApplicationContext(), Main.class);
        Bundle miBundleRuta = new Bundle();
        miBundleRuta.putString("nombre", nom.getText().toString());
        miBundleRuta.putString("codigo", ide.getText().toString());
        MainClass.putExtras(miBundleRuta);
        startActivity(MainClass);
    }
}
