'Form1.Designer.vb
<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Форма переопределяет dispose для очистки списка компонентов.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Является обязательной для конструктора форм Windows Forms
    Private components As System.ComponentModel.IContainer

    'Примечание: следующая процедура является обязательной для конструктора форм Windows Forms
    'Для ее изменения используйте конструктор форм Windows Form.  
    'Не изменяйте ее в редакторе исходного кода.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.TextBox1 = New System.Windows.Forms.TextBox()
        Me.TextBox2 = New System.Windows.Forms.TextBox()
        Me.getMonthButton = New System.Windows.Forms.Button()
        Me.getYearButton = New System.Windows.Forms.Button()
        Me.getMonthTextbox = New System.Windows.Forms.TextBox()
        Me.getYearTextbox = New System.Windows.Forms.TextBox()
        Me.putYearTextbox = New System.Windows.Forms.TextBox()
        Me.putMonthTextBox = New System.Windows.Forms.TextBox()
        Me.putYearButton = New System.Windows.Forms.Button()
        Me.putMonthButton = New System.Windows.Forms.Button()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'TextBox1
        '
        Me.TextBox1.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox1.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(204, Byte))
        Me.TextBox1.Location = New System.Drawing.Point(40, 142)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.ReadOnly = True
        Me.TextBox1.Size = New System.Drawing.Size(69, 24)
        Me.TextBox1.TabIndex = 0
        Me.TextBox1.Text = "Month"
        '
        'TextBox2
        '
        Me.TextBox2.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox2.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(204, Byte))
        Me.TextBox2.Location = New System.Drawing.Point(40, 248)
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.ReadOnly = True
        Me.TextBox2.Size = New System.Drawing.Size(69, 24)
        Me.TextBox2.TabIndex = 1
        Me.TextBox2.Text = "Year"
        '
        'getMonthButton
        '
        Me.getMonthButton.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(204, Byte))
        Me.getMonthButton.Location = New System.Drawing.Point(175, 138)
        Me.getMonthButton.Name = "getMonthButton"
        Me.getMonthButton.Size = New System.Drawing.Size(76, 34)
        Me.getMonthButton.TabIndex = 4
        Me.getMonthButton.Text = "Get"
        Me.getMonthButton.UseVisualStyleBackColor = True
        '
        'getYearButton
        '
        Me.getYearButton.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(204, Byte))
        Me.getYearButton.Location = New System.Drawing.Point(175, 239)
        Me.getYearButton.Name = "getYearButton"
        Me.getYearButton.Size = New System.Drawing.Size(75, 33)
        Me.getYearButton.TabIndex = 5
        Me.getYearButton.Text = "Get"
        Me.getYearButton.UseVisualStyleBackColor = True
        '
        'getMonthTextbox
        '
        Me.getMonthTextbox.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(204, Byte))
        Me.getMonthTextbox.Location = New System.Drawing.Point(257, 140)
        Me.getMonthTextbox.Name = "getMonthTextbox"
        Me.getMonthTextbox.ReadOnly = True
        Me.getMonthTextbox.Size = New System.Drawing.Size(100, 29)
        Me.getMonthTextbox.TabIndex = 6
        '
        'getYearTextbox
        '
        Me.getYearTextbox.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(204, Byte))
        Me.getYearTextbox.Location = New System.Drawing.Point(257, 240)
        Me.getYearTextbox.Name = "getYearTextbox"
        Me.getYearTextbox.ReadOnly = True
        Me.getYearTextbox.Size = New System.Drawing.Size(100, 29)
        Me.getYearTextbox.TabIndex = 7
        '
        'putYearTextbox
        '
        Me.putYearTextbox.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(204, Byte))
        Me.putYearTextbox.Location = New System.Drawing.Point(517, 237)
        Me.putYearTextbox.Name = "putYearTextbox"
        Me.putYearTextbox.Size = New System.Drawing.Size(100, 29)
        Me.putYearTextbox.TabIndex = 11
        '
        'putMonthTextBox
        '
        Me.putMonthTextBox.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(204, Byte))
        Me.putMonthTextBox.Location = New System.Drawing.Point(517, 137)
        Me.putMonthTextBox.Name = "putMonthTextBox"
        Me.putMonthTextBox.Size = New System.Drawing.Size(100, 29)
        Me.putMonthTextBox.TabIndex = 10
        '
        'putYearButton
        '
        Me.putYearButton.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(204, Byte))
        Me.putYearButton.Location = New System.Drawing.Point(435, 236)
        Me.putYearButton.Name = "putYearButton"
        Me.putYearButton.Size = New System.Drawing.Size(75, 33)
        Me.putYearButton.TabIndex = 9
        Me.putYearButton.Text = "Put"
        Me.putYearButton.UseVisualStyleBackColor = True
        '
        'putMonthButton
        '
        Me.putMonthButton.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(204, Byte))
        Me.putMonthButton.Location = New System.Drawing.Point(435, 135)
        Me.putMonthButton.Name = "putMonthButton"
        Me.putMonthButton.Size = New System.Drawing.Size(76, 34)
        Me.putMonthButton.TabIndex = 8
        Me.putMonthButton.Text = "Put"
        Me.putMonthButton.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Times New Roman", 24.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(199, 36)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(310, 36)
        Me.Label1.TabIndex = 12
        Me.Label1.Text = "Change month and year"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(585, 18)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(51, 13)
        Me.Label2.TabIndex = 13
        Me.Label2.Text = "dkotsuba"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(668, 308)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.putYearTextbox)
        Me.Controls.Add(Me.putMonthTextBox)
        Me.Controls.Add(Me.putYearButton)
        Me.Controls.Add(Me.putMonthButton)
        Me.Controls.Add(Me.getYearTextbox)
        Me.Controls.Add(Me.getMonthTextbox)
        Me.Controls.Add(Me.getYearButton)
        Me.Controls.Add(Me.getMonthButton)
        Me.Controls.Add(Me.TextBox2)
        Me.Controls.Add(Me.TextBox1)
        Me.Name = "Form1"
        Me.Text = "SR3 00321 CalClient"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents TextBox1 As TextBox
    Friend WithEvents TextBox2 As TextBox
    Friend WithEvents getMonthButton As Button
    Friend WithEvents getYearButton As Button
    Friend WithEvents getMonthTextbox As TextBox
    Friend WithEvents getYearTextbox As TextBox
    Friend WithEvents putYearTextbox As TextBox
    Friend WithEvents putMonthTextBox As TextBox
    Friend WithEvents putYearButton As Button
    Friend WithEvents putMonthButton As Button
    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
End Class
