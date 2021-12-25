'Form1.vb
Public Class Form1
    Const ITERATIONS = 500000
    Private Sub BtLate_Click(sender As Object, e As EventArgs) Handles BtLate.Click
        ' Пример позднего связывания
        Dim obj As Object
        Dim i As Long
        Dim Start As DateTime = DateTime.Now
        ' Создание объекта с указанным ProgId
        obj = CreateObject("Atl-autoSrv.CoMyMath.1")
        'obj = CreateObject("ATLautoSrvLib.CoMyMath.1")

        txtResult.Text = obj.Add(txtOp1.Text, txtOp2.Text)
        For i = 1 To ITERATIONS
            obj.Add(txtOp1.Text, txtOp2.Text)
        Next
        txtTime1.Text = (DateTime.Now - Start).TotalSeconds
    End Sub

    Private Sub BtVtbl_Click(sender As Object, e As EventArgs) Handles BtVtbl.Click
        ' Пример связывания через vtbl(очень раннего связывания)
        Dim i As Long
        Dim obj As New ATLautoSrvLib.CoMyMath
        Dim Start As DateTime = DateTime.Now
        txtResult.Text = obj.Add(txtOp1.Text, txtOp2.Text)
        For i = 1 To ITERATIONS
            obj.Add(txtOp1.Text, txtOp2.Text)
        Next
        txtTime3.Text = (DateTime.Now - Start).TotalSeconds
    End Sub
End Class

