using System;
using System.Data.SqlClient;
public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        SqlConnection conn = new SqlConnection(@"Data Source=someserver@someplace,1044;Initial Catalog=jacobkapusta;User ID=jakapu;Password=01301234141141");
        string com = "SELECT SUM(OL_Price) FROM Order_Line";
        SqlCommand Comm1 = new SqlCommand(com, conn);
        conn.Open();
        SqlDataReader DR1 = Comm1.ExecuteReader();

        if (DR1.Read())
        {
            TextBox1.Text = DR1.GetValue(0).ToString();
        }
        conn.Close();
    }
}