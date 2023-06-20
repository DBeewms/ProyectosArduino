using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

/*
 * Autores:
 * Diego Mora
 * Carlos Talavera
 * Tutor:
 * José Durán
 * 
 */

namespace MedidorAmor
{
    public partial class Form1 : Form
    {
        bool active = false;
        string texto = "0.0";
        double temperature = 0.0;
        double baselineTemp = 23;

        private void Start()
        {
            try
            {
                if (!active)
                {
                    serialPort1.Open();
                    active = true;
                }
                else
                {
                    serialPort1.Close();
                    active = false;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                serialPort1.PortName = "COM6";
                Start();
                timer1.Enabled = true;
                timer1.Interval = 50;
                timer1.Start();
            }
            catch (Exception ex) { }
        }

        private void getTemp()
        {

        }

        private void btnStart_Click(object sender, EventArgs e)
        {

        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            try
            {
                string[] datos = serialPort1.ReadLine().Split('-');
                texto = datos[0];
            }
            catch (Exception ex) { }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            try
            {
                lblTemp.Text = texto;
                temperature = double.Parse(lblTemp.Text);
                Evaluate();
            }
            catch (Exception ex) { }
        }

        private void Evaluate()
        {
            try
            {
                if (temperature < baselineTemp + 2)
                {
                    
                    this.pictureBox1.Image = global::MedidorAmor.Properties.Resources.CorazonUCA;
                }
                else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4)
                {
                    
                    this.pictureBox1.Image = global::MedidorAmor.Properties.Resources.abeja1;
                }
                else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6)
                {
                   
                    this.pictureBox1.Image = global::MedidorAmor.Properties.Resources.abeja22;
                }
                else if (temperature >= baselineTemp + 6)
                {
                    
                    this.pictureBox1.Image = global::MedidorAmor.Properties.Resources.abeja333;
                }
            }
            catch (Exception ex) { }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
