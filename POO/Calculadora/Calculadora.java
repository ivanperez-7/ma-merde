import java.util.Arrays;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.script.ScriptEngineManager;
import javax.script.ScriptEngine;
import javax.script.ScriptException;

public class Calculadora extends javax.swing.JFrame {

    public Calculadora() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        lbErrores = new javax.swing.JLabel();
        btPoint = new javax.swing.JButton();
        tfInput = new javax.swing.JTextField();
        bt1 = new javax.swing.JButton();
        bt4 = new javax.swing.JButton();
        bt7 = new javax.swing.JButton();
        btLeftParenthesis = new javax.swing.JButton();
        bt2 = new javax.swing.JButton();
        bt0 = new javax.swing.JButton();
        bt5 = new javax.swing.JButton();
        bt8 = new javax.swing.JButton();
        btRightParenthesis = new javax.swing.JButton();
        btEquals = new javax.swing.JButton();
        bt9 = new javax.swing.JButton();
        btDelete = new javax.swing.JButton();
        bt3 = new javax.swing.JButton();
        bt6 = new javax.swing.JButton();
        btDiv = new javax.swing.JButton();
        btMult = new javax.swing.JButton();
        btClear = new javax.swing.JButton();
        btSub = new javax.swing.JButton();
        btSum = new javax.swing.JButton();
        tfResult = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        lbErrores.setFont(new java.awt.Font("Tahoma", 1, 11)); // NOI18N
        lbErrores.setText("Errores");

        btPoint.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        btPoint.setText(".");
        btPoint.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btPointActionPerformed(evt);
            }
        });

        tfInput.setEditable(false);
        tfInput.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        tfInput.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        tfInput.setText("0");
        tfInput.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfInputActionPerformed(evt);
            }
        });

        bt1.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        bt1.setText("1");
        bt1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bt1ActionPerformed(evt);
            }
        });

        bt4.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        bt4.setText("4");
        bt4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bt4ActionPerformed(evt);
            }
        });

        bt7.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        bt7.setText("7");
        bt7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bt7ActionPerformed(evt);
            }
        });

        btLeftParenthesis.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        btLeftParenthesis.setText("(");
        btLeftParenthesis.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btLeftParenthesisActionPerformed(evt);
            }
        });

        bt2.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        bt2.setText("2");
        bt2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bt2ActionPerformed(evt);
            }
        });

        bt0.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        bt0.setText("0");
        bt0.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bt0ActionPerformed(evt);
            }
        });

        bt5.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        bt5.setText("5");
        bt5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bt5ActionPerformed(evt);
            }
        });

        bt8.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        bt8.setText("8");
        bt8.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bt8ActionPerformed(evt);
            }
        });

        btRightParenthesis.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        btRightParenthesis.setText(")");
        btRightParenthesis.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btRightParenthesisActionPerformed(evt);
            }
        });

        btEquals.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        btEquals.setText("=");
        btEquals.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btEqualsActionPerformed(evt);
            }
        });

        bt9.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        bt9.setText("9");
        bt9.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bt9ActionPerformed(evt);
            }
        });

        btDelete.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        btDelete.setText("Del");
        btDelete.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btDeleteActionPerformed(evt);
            }
        });

        bt3.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        bt3.setText("3");
        bt3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bt3ActionPerformed(evt);
            }
        });

        bt6.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        bt6.setText("6");
        bt6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bt6ActionPerformed(evt);
            }
        });

        btDiv.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        btDiv.setText("/");
        btDiv.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btDivActionPerformed(evt);
            }
        });

        btMult.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        btMult.setText("*");
        btMult.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btMultActionPerformed(evt);
            }
        });

        btClear.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        btClear.setText("C");
        btClear.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btClearActionPerformed(evt);
            }
        });

        btSub.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        btSub.setText("-");
        btSub.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btSubActionPerformed(evt);
            }
        });

        btSum.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        btSum.setText("+");
        btSum.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btSumActionPerformed(evt);
            }
        });

        tfResult.setEditable(false);
        tfResult.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        tfResult.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        tfResult.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfResultActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(tfInput)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(lbErrores)
                            .addComponent(btLeftParenthesis, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(bt7, javax.swing.GroupLayout.DEFAULT_SIZE, 75, Short.MAX_VALUE)
                            .addComponent(bt4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(bt1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btPoint, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(btRightParenthesis, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(bt8, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(bt5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(bt2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(bt0, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(btDelete, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(bt9, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(bt6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(bt3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btEquals, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(btClear, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btDiv, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btMult, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btSub, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btSum, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addComponent(tfResult, javax.swing.GroupLayout.Alignment.TRAILING))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(lbErrores)
                .addGap(18, 18, 18)
                .addComponent(tfInput, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(tfResult, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 18, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(btLeftParenthesis, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(bt7, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(bt4, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(bt1, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btPoint, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(btRightParenthesis, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(bt8, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(bt5, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(bt2, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(bt0, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(btDelete, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(bt9, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(bt6, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(bt3, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btEquals, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(btClear, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btDiv, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btMult, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btSub, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btSum, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(25, 25, 25))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btPointActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btPointActionPerformed
        this.tfInput.setText(this.tfInput.getText() + ".");
    }//GEN-LAST:event_btPointActionPerformed

    private void tfInputActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfInputActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfInputActionPerformed

    private void bt1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bt1ActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "1");
    }//GEN-LAST:event_bt1ActionPerformed

    private void bt4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bt4ActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "4");
    }//GEN-LAST:event_bt4ActionPerformed

    private void bt7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bt7ActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "7");
    }//GEN-LAST:event_bt7ActionPerformed

    private void btLeftParenthesisActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btLeftParenthesisActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "(");
    }//GEN-LAST:event_btLeftParenthesisActionPerformed

    private void bt2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bt2ActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "2");
    }//GEN-LAST:event_bt2ActionPerformed

    private void bt0ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bt0ActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "0");
    }//GEN-LAST:event_bt0ActionPerformed

    private void bt5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bt5ActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "5");
    }//GEN-LAST:event_bt5ActionPerformed

    private void bt8ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bt8ActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "8");
    }//GEN-LAST:event_bt8ActionPerformed

    private void btRightParenthesisActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btRightParenthesisActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + ")");
    }//GEN-LAST:event_btRightParenthesisActionPerformed

    private void btEqualsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btEqualsActionPerformed
        ScriptEngineManager mgr = new ScriptEngineManager();
        ScriptEngine engine = mgr.getEngineByName("JavaScript");

        try{ 
            Object res = engine.eval(this.tfInput.getText());

            try {
                int out_i = (int) res; 
                this.tfResult.setText(Integer.toString(out_i));
            }
            catch(ClassCastException ex) {
                double out_d = (double) res;
                
                if("Infinity".equals(Double.toString(out_d)) || "-Infinity".equals(Double.toString(out_d)))
                    this.tfResult.setText("No se puede dividir entre cero!");
                else
                    this.tfResult.setText(Double.toString(out_d));
            }
        }
        catch(ScriptException ex){ 
            this.tfResult.setText("Error! Try again."); 
        }
    }//GEN-LAST:event_btEqualsActionPerformed

    private void bt9ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bt9ActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "9");
    }//GEN-LAST:event_bt9ActionPerformed

    private void btDeleteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btDeleteActionPerformed
        String x = this.tfInput.getText();
        char[] c = x.toCharArray();
        c[0] = 'x';
        this.tfInput.setText(Arrays.toString(c));
    }//GEN-LAST:event_btDeleteActionPerformed

    private void bt3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bt3ActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "3");
    }//GEN-LAST:event_bt3ActionPerformed

    private void bt6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bt6ActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "6");
    }//GEN-LAST:event_bt6ActionPerformed

    private void btDivActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btDivActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "/");
    }//GEN-LAST:event_btDivActionPerformed

    private void btMultActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btMultActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "*");
    }//GEN-LAST:event_btMultActionPerformed

    private void btClearActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btClearActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText("0");
    }//GEN-LAST:event_btClearActionPerformed

    private void btSubActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btSubActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "-");
    }//GEN-LAST:event_btSubActionPerformed

    private void btSumActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btSumActionPerformed
        if("0".equals(this.tfInput.getText()))
            this.tfInput.setText("");
        this.tfInput.setText(this.tfInput.getText() + "+");
    }//GEN-LAST:event_btSumActionPerformed

    private void tfResultActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfResultActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfResultActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Calculadora.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Calculadora.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Calculadora.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Calculadora.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Calculadora().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton bt0;
    private javax.swing.JButton bt1;
    private javax.swing.JButton bt2;
    private javax.swing.JButton bt3;
    private javax.swing.JButton bt4;
    private javax.swing.JButton bt5;
    private javax.swing.JButton bt6;
    private javax.swing.JButton bt7;
    private javax.swing.JButton bt8;
    private javax.swing.JButton bt9;
    private javax.swing.JButton btClear;
    private javax.swing.JButton btDelete;
    private javax.swing.JButton btDiv;
    private javax.swing.JButton btEquals;
    private javax.swing.JButton btLeftParenthesis;
    private javax.swing.JButton btMult;
    private javax.swing.JButton btPoint;
    private javax.swing.JButton btRightParenthesis;
    private javax.swing.JButton btSub;
    private javax.swing.JButton btSum;
    private javax.swing.JLabel lbErrores;
    private javax.swing.JTextField tfInput;
    private javax.swing.JTextField tfResult;
    // End of variables declaration//GEN-END:variables
}
