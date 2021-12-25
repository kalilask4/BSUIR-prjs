'Form1.Designer.vb
<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        'components = New System.ComponentModel.Container()
        'Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        'Me.ClientSize = New System.Drawing.Size(800, 450)
        'Me.Text = "Form1"
        Me.txtOp1 = New System.Windows.Forms.TextBox()
        Me.txtOp2 = New System.Windows.Forms.TextBox()
        Me.txtResult = New System.Windows.Forms.TextBox()
        Me.BtLate = New System.Windows.Forms.Button()
        Me.BtVtbl = New System.Windows.Forms.Button()
        Me.txtTime1 = New System.Windows.Forms.TextBox()
        Me.txtTime3 = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'txtOp1
        '
        Me.txtOp1.Location = New System.Drawing.Point(13, 34)
        Me.txtOp1.Name = "txtOp1"
        Me.txtOp1.Size = New System.Drawing.Size(148, 20)
        Me.txtOp1.TabIndex = 0
        Me.txtOp1.Text = "7"
        '
        'txtOp2
        '
        Me.txtOp2.Location = New System.Drawing.Point(209, 34)
        Me.txtOp2.Name = "txtOp2"
        Me.txtOp2.Size = New System.Drawing.Size(148, 20)
        Me.txtOp2.TabIndex = 1
        Me.txtOp2.Text = "44"
        '
        'txtResult
        '
        Me.txtResult.Location = New System.Drawing.Point(399, 34)
        Me.txtResult.Name = "txtResult"
        Me.txtResult.Size = New System.Drawing.Size(148, 20)
        Me.txtResult.TabIndex = 2
        '
        'BtLate
        '
        Me.BtLate.Location = New System.Drawing.Point(35, 98)
        Me.BtLate.Name = "BtLate"
        Me.BtLate.Size = New System.Drawing.Size(98, 30)
        Me.BtLate.TabIndex = 3
        Me.BtLate.Text = "Late"
        Me.BtLate.UseVisualStyleBackColor = True
        '
        'BtVtbl
        '
        Me.BtVtbl.Location = New System.Drawing.Point(35, 167)
        Me.BtVtbl.Name = "BtVtbl"
        Me.BtVtbl.Size = New System.Drawing.Size(98, 30)
        Me.BtVtbl.TabIndex = 4
        Me.BtVtbl.Text = "Vtbl"
        Me.BtVtbl.UseVisualStyleBackColor = True
        '
        'txtTime1
        '
        Me.txtTime1.Location = New System.Drawing.Point(209, 108)
        Me.txtTime1.Name = "txtTime1"
        Me.txtTime1.Size = New System.Drawing.Size(148, 20)
        Me.txtTime1.TabIndex = 5
        '
        'txtTime3
        '
        Me.txtTime3.Location = New System.Drawing.Point(209, 177)
        Me.txtTime3.Name = "txtTime3"
        Me.txtTime3.Size = New System.Drawing.Size(148, 20)
        Me.txtTime3.TabIndex = 6
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.txtTime3)
        Me.Controls.Add(Me.txtTime1)
        Me.Controls.Add(Me.BtVtbl)
        Me.Controls.Add(Me.BtLate)
        Me.Controls.Add(Me.txtResult)
        Me.Controls.Add(Me.txtOp2)
        Me.Controls.Add(Me.txtOp1)
        Me.Name = "VB client, 00321"
        Me.Text = "Kotsuba Diana Visual Basic Client Test"
        Me.ResumeLayout(False)
        Me.PerformLayout()



    End Sub
    Friend WithEvents txtOp1 As TextBox
    Friend WithEvents txtOp2 As TextBox
    Friend WithEvents txtResult As TextBox
    Friend WithEvents BtLate As Button
    Friend WithEvents BtVtbl As Button
    Friend WithEvents txtTime1 As TextBox
    Friend WithEvents txtTime3 As TextBox

End Class
