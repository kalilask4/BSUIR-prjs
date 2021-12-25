'Form1.vb
Public Class Form1

    Dim obj As Object

    Public Sub New()
        InitializeComponent()
        obj = CreateObject("MSCAL.Календарь.7")
    End Sub

    Private Sub getMonthButton_Click(sender As Object, e As EventArgs) Handles getMonthButton.Click
        getMonthTextbox.Text = obj.Month
    End Sub

    Private Sub putMonthButton_Click(sender As Object, e As EventArgs) Handles putMonthButton.Click
        obj.Month = putMonthTextBox.Text
    End Sub


    Private Sub getYearButton_Click(sender As Object, e As EventArgs) Handles getYearButton.Click
        getYearTextbox.Text = obj.Year
    End Sub


    Private Sub putYearButton_Click(sender As Object, e As EventArgs) Handles putYearButton.Click
        obj.Year = putYearTextbox.Text
    End Sub


End Class
