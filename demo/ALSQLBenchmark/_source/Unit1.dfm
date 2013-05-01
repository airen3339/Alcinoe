object Form1: TForm1
  Left = 445
  Top = 202
  Caption = 'ALSQLBenchmark'
  ClientHeight = 764
  ClientWidth = 1007
  Color = 15986666
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClick = FormClick
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar1: TStatusBar
    Left = 0
    Top = 745
    Width = 1007
    Height = 19
    Color = 15525605
    Panels = <
      item
        Width = 150
      end
      item
        Width = 700
      end>
  end
  object Panel3: TPanel
    Left = 0
    Top = 329
    Width = 1007
    Height = 416
    Align = alClient
    Caption = 'Panel2'
    TabOrder = 2
    object Splitter4: TSplitter
      Left = 709
      Top = 1
      Height = 414
      Align = alRight
      ExplicitLeft = 624
      ExplicitTop = -3
      ExplicitHeight = 469
    end
    object Panel5: TPanel
      Left = 712
      Top = 1
      Width = 294
      Height = 414
      Align = alRight
      Caption = 'Panel2'
      TabOrder = 0
      object ALMemoResult: TcxMemo
        Left = 1
        Top = 1
        Align = alClient
        ParentFont = False
        Properties.ReadOnly = True
        Properties.ScrollBars = ssVertical
        Style.Color = clBtnFace
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -11
        Style.Font.Name = 'Tahoma'
        Style.Font.Style = []
        Style.IsFontAssigned = True
        TabOrder = 0
        Height = 259
        Width = 292
      end
      object Panel2: TPanel
        Left = 1
        Top = 260
        Width = 292
        Height = 153
        Align = alBottom
        BevelOuter = bvNone
        BorderStyle = bsSingle
        Color = clSilver
        Ctl3D = False
        ParentBackground = False
        ParentCtl3D = False
        TabOrder = 1
        object Panel4: TPanel
          Left = 151
          Top = 8
          Width = 130
          Height = 134
          BevelOuter = bvNone
          BorderStyle = bsSingle
          Color = clWhite
          Ctl3D = False
          ParentBackground = False
          ParentCtl3D = False
          TabOrder = 0
          object PanelWebBrowser: TPanel
            Left = -5
            Top = -23
            Width = 133
            Height = 159
            BevelOuter = bvNone
            Color = clMedGray
            Ctl3D = False
            ParentBackground = False
            ParentCtl3D = False
            TabOrder = 0
          end
        end
        object cxLabel1: TcxLabel
          Left = 4
          Top = 3
          Caption = 'Please help us to keep the development of these components free'
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clMaroon
          Style.Font.Height = -12
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = [fsBold]
          Style.TextColor = clMaroon
          Style.IsFontAssigned = True
          Properties.WordWrap = True
          Width = 145
        end
        object cxLabel2: TcxLabel
          Left = 4
          Top = 68
          Caption = 
            'If you like these components please simply click on each button ' +
            'below ... thanks for your support !'
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clWindowText
          Style.Font.Height = -12
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = []
          Style.IsFontAssigned = True
          Properties.WordWrap = True
          Width = 135
        end
      end
    end
    object PanelStats: TPanel
      Left = 1
      Top = 1
      Width = 708
      Height = 414
      Align = alClient
      Caption = 'Panel2'
      TabOrder = 1
      object GridThread: TcxGrid
        Left = 1
        Top = 1
        Width = 706
        Height = 412
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object TableViewThread: TcxGridTableView
          Navigator.Buttons.First.Visible = False
          Navigator.Buttons.PriorPage.Visible = False
          Navigator.Buttons.Prior.Visible = False
          Navigator.Buttons.Next.Visible = False
          Navigator.Buttons.NextPage.Visible = False
          Navigator.Buttons.Last.Visible = False
          Navigator.Buttons.Edit.Visible = True
          Navigator.Buttons.Refresh.Visible = False
          Navigator.Buttons.SaveBookmark.Visible = False
          Navigator.Buttons.GotoBookmark.Visible = False
          Navigator.Buttons.Filter.Visible = False
          FilterBox.CustomizeDialog = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          Filtering.MRUItemsList = False
          Filtering.ColumnMRUItemsList = False
          OptionsBehavior.FocusCellOnTab = True
          OptionsBehavior.FocusFirstCellOnNewRecord = True
          OptionsBehavior.GoToNextCellOnEnter = True
          OptionsBehavior.ImmediateEditor = False
          OptionsBehavior.FocusCellOnCycle = True
          OptionsCustomize.ColumnFiltering = False
          OptionsCustomize.ColumnGrouping = False
          OptionsCustomize.ColumnHidingOnGrouping = False
          OptionsData.Deleting = False
          OptionsData.DeletingConfirmation = False
          OptionsData.Editing = False
          OptionsData.Inserting = False
          OptionsSelection.HideSelection = True
          OptionsView.CellEndEllipsis = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          OptionsView.HeaderEndEllipsis = True
          Styles.Background = cxStyle1
          object TableViewThreadNumber: TcxGridColumn
            Caption = 'Thread #'
            Width = 61
          end
          object TableViewThreadCount: TcxGridColumn
            Caption = 'Count'
            DataBinding.ValueType = 'Integer'
            Width = 46
          end
          object TableViewThreadAveragePrepareTimeTaken: TcxGridColumn
            Caption = 'Average Prepare (ms) / rec'
            DataBinding.ValueType = 'Float'
            HeaderAlignmentHorz = taCenter
            Width = 155
          end
          object TableViewThreadAverageExecuteTimeTaken: TcxGridColumn
            Caption = 'Average Execute (ms) / rec'
            DataBinding.ValueType = 'Float'
            HeaderAlignmentHorz = taCenter
            Width = 151
          end
          object TableViewThreadAverageCommitTimeTaken: TcxGridColumn
            Caption = 'Average Commit (ms) / rec'
            DataBinding.ValueType = 'Float'
            HeaderAlignmentHorz = taCenter
            Width = 160
          end
          object TableViewThreadErrorMsg: TcxGridColumn
            Caption = 'Error Msg'
            HeaderAlignmentHorz = taCenter
            Width = 131
          end
        end
        object levelThread: TcxGridLevel
          GridView = TableViewThread
        end
      end
    end
  end
  object PageControl1: TcxPageControl
    Left = 0
    Top = 0
    Width = 1007
    Height = 329
    Align = alTop
    Color = clBtnFace
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
    Properties.ActivePage = Firebird
    ClientRectBottom = 324
    ClientRectLeft = 5
    ClientRectRight = 1002
    ClientRectTop = 26
    object Firebird: TcxTabSheet
      Caption = 'Firebird'
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label2: TcxLabel
        Left = 71
        Top = 93
        Caption = 'Login'
        ParentFont = False
        Transparent = True
      end
      object Label4: TcxLabel
        Left = 50
        Top = 118
        Caption = 'Password'
        ParentFont = False
        Transparent = True
      end
      object Label15: TcxLabel
        Left = 58
        Top = 143
        Caption = 'Charset'
        ParentFont = False
        Transparent = True
      end
      object Label16: TcxLabel
        Left = 37
        Top = 43
        Caption = 'FBClient DLL'
        ParentFont = False
        Transparent = True
      end
      object Label17: TcxLabel
        Left = 404
        Top = 19
        Caption = 'SQL'
        ParentFont = False
        Transparent = True
      end
      object Label18: TcxLabel
        Left = 50
        Top = 69
        Caption = 'Database'
        ParentFont = False
        Transparent = True
      end
      object Label13: TcxLabel
        Left = 841
        Top = 202
        Caption = 'Nb Loop:'
        ParentFont = False
        Transparent = True
      end
      object Label26: TcxLabel
        Left = 814
        Top = 227
        Caption = 'Commit every:'
        ParentFont = False
        Transparent = True
      end
      object Label29: TcxLabel
        Left = 830
        Top = 177
        Caption = 'Nb Thread:'
        ParentFont = False
        Transparent = True
      end
      object Label30: TcxLabel
        Left = 34
        Top = 167
        Caption = 'Num_buffers'
        ParentFont = False
        Transparent = True
      end
      object Label31: TcxLabel
        Left = 22
        Top = 19
        Caption = 'Firebird Version'
        ParentFont = False
        Transparent = True
      end
      object Label1: TcxLabel
        Left = 387
        Top = 146
        Caption = 'Params'
        ParentFont = False
        Transparent = True
      end
      object Label14: TcxLabel
        Left = 373
        Top = 161
        Caption = '(1 by row)'
        ParentFont = False
        Transparent = True
      end
      object Label27: TcxLabel
        Left = 78
        Top = 194
        Caption = 'TPB'
        ParentFont = False
        Transparent = True
      end
      object ALButtonFirebirdSelect: TcxButton
        Left = 807
        Top = 50
        Width = 161
        Height = 25
        Caption = 'SELECT'
        TabOrder = 10
        OnClick = ALButtonFirebirdSelectClick
      end
      object ALEditFirebirdLogin: TcxTextEdit
        Left = 106
        Top = 93
        TabOrder = 2
        Text = 'SYSDBA'
        Width = 249
      end
      object ALEditFirebirdPassword: TcxTextEdit
        Left = 106
        Top = 118
        TabOrder = 3
        Width = 249
      end
      object ALEditFirebirdCharset: TcxTextEdit
        Left = 106
        Top = 143
        TabOrder = 4
        Text = 'NONE'
        Width = 72
      end
      object ALEditFirebirdLib: TcxButtonEdit
        Left = 106
        Top = 43
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = ALEditButtonFindFileClick
        TabOrder = 0
        Text = 'FBClient.dll'
        Width = 249
      end
      object ALMemoFireBirdQuery: TcxMemo
        Left = 432
        Top = 16
        Lines.Strings = (
          'Select '
          '  FieldA'
          'From'
          '  TableSample'
          'Where'
          '  fieldB = ? or'
          '  fieldC= ?'
          '  ')
        ParentFont = False
        Properties.ScrollBars = ssVertical
        TabOrder = 7
        Height = 121
        Width = 338
      end
      object ALEditFirebirdDatabase: TcxButtonEdit
        Left = 106
        Top = 69
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = ALEditButtonFindFileClick
        TabOrder = 1
        Width = 249
      end
      object ALButtonFirebirdLoopSelect: TcxButton
        Left = 807
        Top = 112
        Width = 161
        Height = 25
        Caption = 'Loop SELECT'
        TabOrder = 12
        OnClick = ALButtonFirebirdLoopSelectClick
      end
      object ALButtonFirebirdUpdate: TcxButton
        Left = 807
        Top = 81
        Width = 161
        Height = 25
        Caption = 'UPDATE'
        TabOrder = 11
        OnClick = ALButtonFirebirdUpdateClick
      end
      object ALButtonFirebirdLoopUpdate: TcxButton
        Left = 807
        Top = 143
        Width = 161
        Height = 25
        Caption = 'Loop UPDATE'
        TabOrder = 13
        OnClick = ALButtonFirebirdLoopUpdateClick
      end
      object ALEditFirebirdNBLoop: TcxTextEdit
        Left = 894
        Top = 199
        TabOrder = 15
        Text = '1000000'
        Width = 74
      end
      object ALEditFirebirdNbLoopBeforeCommit: TcxTextEdit
        Left = 894
        Top = 224
        TabOrder = 16
        Text = '1'
        Width = 74
      end
      object ALEditFirebirdNBThread: TcxTextEdit
        Left = 894
        Top = 174
        TabOrder = 14
        Text = '1'
        Width = 74
      end
      object ALEditFireBirdNum_buffers: TcxTextEdit
        Left = 106
        Top = 167
        TabOrder = 5
        Text = '0'
        Width = 46
      end
      object ALButtonFirebirdCreateDatabase: TcxButton
        Left = 807
        Top = 19
        Width = 161
        Height = 25
        Caption = 'Create Database'
        TabOrder = 9
        OnClick = ALButtonFirebirdCreateDatabaseClick
      end
      object ALMemoFireBirdParams: TcxMemo
        Left = 432
        Top = 143
        Lines.Strings = (
          '<#randomString maxlength=50>'
          '<#randomNumber>')
        ParentFont = False
        Properties.ScrollBars = ssVertical
        TabOrder = 8
        Height = 134
        Width = 338
      end
      object ALMemoFirebirdTPB: TcxMemo
        Left = 106
        Top = 192
        Lines.Strings = (
          'isc_tpb_version3'
          'isc_tpb_write'
          'isc_tpb_read_committed'
          'isc_tpb_no_rec_version'
          'isc_tpb_nowait')
        Properties.ScrollBars = ssVertical
        TabOrder = 6
        Height = 85
        Width = 249
      end
      object ALComboBoxFirebirdapiVer: TcxComboBox
        Left = 106
        Top = 17
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          'FB102'
          'FB103'
          'FB15'
          'FB20'
          'FB25')
        TabOrder = 31
        Text = 'FB25'
        Width = 121
      end
    end
    object MySQL: TcxTabSheet
      Caption = 'MySQL'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label3: TcxLabel
        Left = 45
        Top = 74
        Caption = 'Host Name'
        ParentFont = False
        Transparent = True
      end
      object Label6: TcxLabel
        Left = 72
        Top = 148
        Caption = 'Login'
        ParentFont = False
        Transparent = True
      end
      object Label7: TcxLabel
        Left = 51
        Top = 173
        Caption = 'Password'
        ParentFont = False
        Transparent = True
      end
      object Label8: TcxLabel
        Left = 37
        Top = 99
        Caption = 'Port Number'
        ParentFont = False
        Transparent = True
      end
      object Label10: TcxLabel
        Left = 59
        Top = 198
        Caption = 'Charset'
        ParentFont = False
        Transparent = True
      end
      object Label11: TcxLabel
        Left = 43
        Top = 49
        Caption = 'LibMySql dll'
        ParentFont = False
        Transparent = True
      end
      object Label9: TcxLabel
        Left = 377
        Top = 22
        Caption = 'SQL'
        ParentFont = False
        Transparent = True
      end
      object Label12: TcxLabel
        Left = 51
        Top = 124
        Caption = 'Database'
        ParentFont = False
        Transparent = True
      end
      object Label32: TcxLabel
        Left = 839
        Top = 182
        Caption = 'Nb Loop:'
        ParentFont = False
        Transparent = True
      end
      object Label33: TcxLabel
        Left = 812
        Top = 207
        Caption = 'Commit every:'
        ParentFont = False
        Transparent = True
      end
      object Label34: TcxLabel
        Left = 828
        Top = 157
        Caption = 'Nb Thread:'
        ParentFont = False
        Transparent = True
      end
      object Label40: TcxLabel
        Left = 18
        Top = 23
        Caption = 'LibMySql Version'
        ParentFont = False
        Transparent = True
      end
      object ALEditMySqlHost: TcxTextEdit
        Left = 106
        Top = 71
        TabOrder = 1
        Text = 'localhost'
        Width = 218
      end
      object ALEditMySqlLogin: TcxTextEdit
        Left = 106
        Top = 145
        TabOrder = 4
        Text = 'root'
        Width = 218
      end
      object ALEditMySqlPassword: TcxTextEdit
        Left = 106
        Top = 170
        TabOrder = 5
        Width = 218
      end
      object ALEditMySqlPort: TcxTextEdit
        Left = 106
        Top = 96
        TabOrder = 2
        Text = '3306'
        Width = 88
      end
      object ALEditMySqlCharset: TcxTextEdit
        Left = 106
        Top = 195
        TabOrder = 6
        Text = 'utf8'
        Width = 218
      end
      object ALEditMysqlLib: TcxButtonEdit
        Left = 106
        Top = 46
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = ALEditButtonFindFileClick
        TabOrder = 0
        Text = 'libmysql.dll'
        Width = 218
      end
      object ALMemoMySqlQuery: TcxMemo
        Left = 406
        Top = 21
        Lines.Strings = (
          'Select '
          '  FieldA'
          'From'
          '  TableSample'
          'Where'
          '  fieldB = '#39'<#randomString maxlength=50>'#39' or'
          '  fieldC= <#randomNumber>')
        ParentFont = False
        Properties.ScrollBars = ssVertical
        TabOrder = 7
        Height = 258
        Width = 338
      end
      object ALButtonMySQLSelect: TcxButton
        Left = 803
        Top = 22
        Width = 161
        Height = 25
        Caption = 'SELECT'
        TabOrder = 8
        OnClick = ALButtonMySqlSelectClick
      end
      object ALEditMySqlDatabaseName: TcxTextEdit
        Left = 106
        Top = 121
        TabOrder = 3
        Width = 218
      end
      object ALEditMySqlNBLoop: TcxTextEdit
        Left = 890
        Top = 179
        TabOrder = 13
        Text = '1000000'
        Width = 74
      end
      object ALEditMySqlNbLoopBeforeCommit: TcxTextEdit
        Left = 890
        Top = 204
        TabOrder = 14
        Text = '1'
        Width = 74
      end
      object ALEditMySqlNBThread: TcxTextEdit
        Left = 890
        Top = 154
        TabOrder = 12
        Text = '1'
        Width = 74
      end
      object ALButtonMysqlUpdate: TcxButton
        Left = 803
        Top = 53
        Width = 161
        Height = 25
        Caption = 'UPDATE'
        TabOrder = 9
        OnClick = ALButtonMysqlUpdateClick
      end
      object ALButtonMySqlLoopUpdate: TcxButton
        Left = 803
        Top = 115
        Width = 161
        Height = 25
        Caption = 'Loop UPDATE'
        TabOrder = 11
        OnClick = ALButtonMySqlLoopUpdateClick
      end
      object ALButtonMysqlLoopSelect: TcxButton
        Left = 803
        Top = 84
        Width = 161
        Height = 25
        Caption = 'Loop SELECT'
        TabOrder = 10
        OnClick = ALButtonMysqlLoopSelectClick
      end
      object ALComboBoxMySqlApiVer: TcxComboBox
        Left = 106
        Top = 21
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          'MYSQL50'
          'MYSQL55')
        TabOrder = 27
        Text = 'MYSQL50'
        Width = 121
      end
    end
    object SQLLite3: TcxTabSheet
      Caption = 'SQLLite3'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label24: TcxLabel
        Left = 17
        Top = 21
        Caption = 'Sqlite3.dll'
        ParentFont = False
        Transparent = True
      end
      object Label25: TcxLabel
        Left = 378
        Top = 21
        Caption = 'SQL'
        ParentFont = False
        Transparent = True
      end
      object Label19: TcxLabel
        Left = 17
        Top = 46
        Caption = 'Database'
        ParentFont = False
        Transparent = True
      end
      object Label20: TcxLabel
        Left = 831
        Top = 173
        Caption = 'Nb Loop:'
        ParentFont = False
        Transparent = True
      end
      object Label21: TcxLabel
        Left = 11
        Top = 235
        Caption = 'cache_size'
        ParentFont = False
        Transparent = True
      end
      object Label22: TcxLabel
        Left = 15
        Top = 260
        Caption = 'page_size'
        ParentFont = False
        Transparent = True
      end
      object Label23: TcxLabel
        Left = 804
        Top = 198
        Caption = 'Commit every:'
        ParentFont = False
        Transparent = True
      end
      object Label28: TcxLabel
        Left = 819
        Top = 148
        Caption = 'Nb Thread:'
        ParentFont = False
        Transparent = True
      end
      object ALEditSqlite3Lib: TcxButtonEdit
        Left = 73
        Top = 18
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = ALEditButtonFindFileClick
        TabOrder = 0
        Text = 'Sqlite3.dll'
        Width = 249
      end
      object ALMemoSqlite3Query: TcxMemo
        Left = 409
        Top = 18
        Lines.Strings = (
          'Select '
          '  FieldA'
          'From'
          '  TableSample'
          'Where'
          '  fieldB = '#39'<#randomString maxlength=50>'#39' or'
          '  fieldC= <#randomNumber>')
        ParentFont = False
        Properties.ScrollBars = ssVertical
        TabOrder = 9
        Height = 258
        Width = 338
      end
      object ALButtonSqlLite3Select: TcxButton
        Left = 803
        Top = 19
        Width = 161
        Height = 25
        Caption = 'SELECT'
        TabOrder = 10
        OnClick = ALButtonSqlLite3SelectClick
      end
      object ALEditSqlite3Database: TcxButtonEdit
        Left = 73
        Top = 43
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = ALEditButtonFindFileClick
        TabOrder = 1
        Width = 249
      end
      object ALButtonSqlite3LoopSelect: TcxButton
        Left = 803
        Top = 83
        Width = 161
        Height = 25
        Caption = 'Loop SELECT'
        TabOrder = 12
        OnClick = ALButtonSqlite3LoopSelectClick
      end
      object ALButtonSqlite3Update: TcxButton
        Left = 803
        Top = 52
        Width = 161
        Height = 25
        Caption = 'UPDATE'
        TabOrder = 11
        OnClick = ALButtonSqlite3UpdateClick
      end
      object ALButtonSqlite3LoopUpdate: TcxButton
        Left = 803
        Top = 114
        Width = 161
        Height = 25
        Caption = 'Loop UPDATE'
        TabOrder = 13
        OnClick = ALButtonSqlite3LoopUpdateClick
      end
      object ALEditSQLite3NBLoop: TcxTextEdit
        Left = 890
        Top = 170
        TabOrder = 15
        Text = '1000000'
        Width = 74
      end
      object RadioGroupSqlite3Journal_Mode: TcxRadioGroup
        Left = 9
        Top = 79
        Caption = 'journal_mode'
        ParentFont = False
        Properties.Items = <
          item
            Caption = 'DELETE'
          end
          item
            Caption = 'TRUNCATE'
          end
          item
            Caption = 'PERSIST'
          end
          item
            Caption = 'MEMORY'
          end
          item
            Caption = 'WAL'
          end
          item
            Caption = 'OFF'
          end>
        ItemIndex = 0
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -11
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = []
        Style.IsFontAssigned = True
        TabOrder = 2
        Height = 148
        Width = 104
      end
      object RadioGroupSQLite3Temp_Store: TcxRadioGroup
        Left = 119
        Top = 78
        Caption = 'temp_store'
        Properties.Items = <
          item
            Caption = 'DEFAULT'
          end
          item
            Caption = 'FILE'
          end
          item
            Caption = 'MEMORY'
          end>
        ItemIndex = 0
        TabOrder = 3
        Height = 89
        Width = 104
      end
      object RadioGroupSqlite3Synhcronous: TcxRadioGroup
        Left = 229
        Top = 78
        Caption = 'synchronous '
        Properties.Items = <
          item
            Caption = 'OFF'
          end
          item
            Caption = 'NORMAL'
          end
          item
            Caption = 'FULL'
          end>
        ItemIndex = 2
        TabOrder = 4
        Height = 89
        Width = 104
      end
      object ALEditSqlite3Cache_Size: TcxTextEdit
        Left = 73
        Top = 232
        TabOrder = 5
        Text = '2000'
        Width = 43
      end
      object ALEditSqlite3Page_Size: TcxTextEdit
        Left = 73
        Top = 257
        TabOrder = 6
        Text = '1024'
        Width = 46
      end
      object ALEditSQLite3NbLoopBeforeCommit: TcxTextEdit
        Left = 890
        Top = 195
        TabOrder = 16
        Text = '1'
        Width = 74
      end
      object ALEditSqlite3NBThread: TcxTextEdit
        Left = 890
        Top = 145
        TabOrder = 14
        Text = '1'
        Width = 74
      end
      object ALCheckBoxSqlite3SharedCache: TcxCheckBox
        Left = 141
        Top = 235
        Caption = 'shared cache'
        ParentFont = False
        TabOrder = 7
        Transparent = True
        Width = 97
      end
      object ALCheckBoxSqlite3ReadUncommited: TcxCheckBox
        Left = 141
        Top = 257
        Caption = 'read uncommitted'
        ParentFont = False
        TabOrder = 8
        Transparent = True
        Width = 124
      end
    end
    object Sphinx: TcxTabSheet
      Caption = 'Sphinx'
      ImageIndex = 3
      ExplicitLeft = 7
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label36: TcxLabel
        Left = 38
        Top = 49
        Caption = 'LibMysql dll'
        ParentFont = False
        Transparent = True
      end
      object Label37: TcxLabel
        Left = 39
        Top = 75
        Caption = 'Host Name'
        ParentFont = False
        Transparent = True
      end
      object Label38: TcxLabel
        Left = 31
        Top = 100
        Caption = 'Port Number'
        ParentFont = False
        Transparent = True
      end
      object Label43: TcxLabel
        Left = 372
        Top = 21
        Caption = 'SQL'
        ParentFont = False
        Transparent = True
      end
      object Label44: TcxLabel
        Left = 819
        Top = 156
        Caption = 'Nb Thread:'
        ParentFont = False
        Transparent = True
      end
      object Label45: TcxLabel
        Left = 831
        Top = 181
        Caption = 'Nb Loop:'
        ParentFont = False
        Transparent = True
      end
      object Label46: TcxLabel
        Left = 804
        Top = 206
        Caption = 'Commit every:'
        ParentFont = False
        Transparent = True
      end
      object Label39: TcxLabel
        Left = 12
        Top = 24
        Caption = 'LibMySql Version'
        ParentFont = False
        Transparent = True
      end
      object ALEditSphinxLib: TcxButtonEdit
        Left = 104
        Top = 47
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = ALEditButtonFindFileClick
        TabOrder = 0
        Text = 'libmysql.dll'
        Width = 221
      end
      object ALEditSphinxHost: TcxTextEdit
        Left = 104
        Top = 72
        TabOrder = 1
        Text = 'localhost'
        Width = 221
      end
      object ALEditSphinxPort: TcxTextEdit
        Left = 104
        Top = 97
        TabOrder = 2
        Text = '9306'
        Width = 88
      end
      object ALMemoSphinxQuery: TcxMemo
        Left = 403
        Top = 18
        Lines.Strings = (
          'Select '
          '  FieldA'
          'From'
          '  TableSample'
          'Where'
          '  fieldC= <#randomNumber>')
        ParentFont = False
        Properties.ScrollBars = ssVertical
        TabOrder = 3
        Height = 258
        Width = 338
      end
      object ALButtonSphinxSelect: TcxButton
        Left = 803
        Top = 21
        Width = 161
        Height = 25
        Caption = 'SELECT'
        TabOrder = 4
        OnClick = ALButtonSphinxSelectClick
      end
      object ALButtonSphinxUpdate: TcxButton
        Left = 804
        Top = 52
        Width = 161
        Height = 25
        Caption = 'UPDATE'
        TabOrder = 5
        OnClick = ALButtonSphinxUpdateClick
      end
      object ALButtonSphinxLoopSelect: TcxButton
        Left = 803
        Top = 83
        Width = 161
        Height = 25
        Caption = 'Loop SELECT'
        TabOrder = 6
        OnClick = ALButtonSphinxLoopSelectClick
      end
      object ALButtonSphinxLoopUpdate: TcxButton
        Left = 803
        Top = 114
        Width = 161
        Height = 25
        Caption = 'Loop UPDATE'
        TabOrder = 7
        OnClick = ALButtonSphinxLoopUpdateClick
      end
      object ALEditSphinxNBThread: TcxTextEdit
        Left = 890
        Top = 153
        TabOrder = 8
        Text = '1'
        Width = 74
      end
      object ALEditSphinxNBLoop: TcxTextEdit
        Left = 890
        Top = 178
        TabOrder = 9
        Text = '1000000'
        Width = 74
      end
      object ALEditSphinxNbLoopBeforeCommit: TcxTextEdit
        Left = 891
        Top = 205
        TabOrder = 10
        Text = '1'
        Width = 74
      end
      object ALComboBoxSphinxApiVer: TcxComboBox
        Left = 104
        Top = 22
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          'MYSQL50'
          'MYSQL55')
        TabOrder = 19
        Text = 'MYSQL50'
        Width = 121
      end
    end
    object MemCached: TcxTabSheet
      Caption = 'MemCached'
      ImageIndex = 4
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label41: TcxLabel
        Left = 25
        Top = 21
        Caption = 'Host Name'
        ParentFont = False
        Transparent = True
      end
      object Label42: TcxLabel
        Left = 17
        Top = 46
        Caption = 'Port Number'
        ParentFont = False
        Transparent = True
      end
      object Label47: TcxLabel
        Left = 365
        Top = 97
        Caption = 'DATA'
        ParentFont = False
        Transparent = True
      end
      object Label48: TcxLabel
        Left = 820
        Top = 196
        Caption = 'Nb Thread:'
        ParentFont = False
        Transparent = True
      end
      object Label49: TcxLabel
        Left = 832
        Top = 221
        Caption = 'Nb Loop:'
        ParentFont = False
        Transparent = True
      end
      object ALEditMemCachedHost: TcxTextEdit
        Left = 94
        Top = 18
        TabOrder = 0
        Text = 'localhost'
        Width = 221
      end
      object ALEditMemCachedPort: TcxTextEdit
        Left = 94
        Top = 43
        TabOrder = 1
        Text = '11211'
        Width = 88
      end
      object ALMemoMemCachedData: TcxMemo
        Left = 405
        Top = 96
        Lines.Strings = (
          '<#randomString maxlength=100000>')
        ParentFont = False
        Properties.ScrollBars = ssVertical
        TabOrder = 2
        Height = 180
        Width = 338
      end
      object ALButtonMemcachedGet: TcxButton
        Left = 803
        Top = 18
        Width = 161
        Height = 25
        Caption = 'GET'
        TabOrder = 3
        OnClick = ALButtonMemcachedGetClick
      end
      object ALButtonMemcachedSet: TcxButton
        Left = 804
        Top = 49
        Width = 161
        Height = 25
        Caption = 'SET'
        TabOrder = 4
        OnClick = ALButtonMemcachedSetClick
      end
      object ALButtonMemcachedLoopGet: TcxButton
        Left = 805
        Top = 112
        Width = 161
        Height = 25
        Caption = 'Loop GET'
        TabOrder = 5
        OnClick = ALButtonMemcachedLoopGetClick
      end
      object ALButtonMemcachedLoopSet: TcxButton
        Left = 805
        Top = 143
        Width = 161
        Height = 25
        Caption = 'Loop SET'
        TabOrder = 6
        OnClick = ALButtonMemcachedLoopSetClick
      end
      object ALEditMemcachedNBThread: TcxTextEdit
        Left = 892
        Top = 191
        TabOrder = 7
        Text = '1'
        Width = 74
      end
      object ALEditMemCachedNBLoop: TcxTextEdit
        Left = 891
        Top = 218
        TabOrder = 8
        Text = '1000000'
        Width = 74
      end
      object ALButtonMemcachedStats: TcxButton
        Left = 17
        Top = 97
        Width = 88
        Height = 25
        Caption = 'STATS'
        TabOrder = 9
        OnClick = ALButtonMemcachedStatsClick
      end
      object ALButtonMemcachedStatsSettings: TcxButton
        Left = 17
        Top = 128
        Width = 88
        Height = 25
        Caption = 'STATS Settings'
        TabOrder = 10
        OnClick = ALButtonMemcachedStatsSettingsClick
      end
      object ALButtonMemcachedStatsItems: TcxButton
        Left = 17
        Top = 159
        Width = 88
        Height = 25
        Caption = 'STATS items'
        TabOrder = 11
        OnClick = ALButtonMemcachedStatsItemsClick
      end
      object ALButtonMemcachedStatsSizes: TcxButton
        Left = 17
        Top = 221
        Width = 88
        Height = 25
        Caption = 'STATS sizes'
        TabOrder = 12
        OnClick = ALButtonMemcachedStatsSizesClick
      end
      object ALButtonMemcachedStatsSlabs: TcxButton
        Left = 17
        Top = 190
        Width = 88
        Height = 25
        Caption = 'STATS slabs'
        TabOrder = 13
        OnClick = ALButtonMemcachedStatsSlabsClick
      end
      object ALButtonMemcachedFLush_ALL: TcxButton
        Left = 131
        Top = 94
        Width = 88
        Height = 25
        Caption = 'FLUSH_ALL'
        TabOrder = 19
        OnClick = ALButtonMemcachedFLush_ALLClick
      end
      object ALButtonMemcachedVersion: TcxButton
        Left = 131
        Top = 128
        Width = 88
        Height = 25
        Caption = 'VERSION'
        TabOrder = 20
        OnClick = ALButtonMemcachedVersionClick
      end
      object ALEditMemCachedKey: TcxTextEdit
        Left = 405
        Top = 18
        TabOrder = 21
        Text = '<#randomString maxlength=250>'
        Width = 338
      end
      object ALlabel123123: TcxLabel
        Left = 374
        Top = 19
        Caption = 'Key'
        ParentFont = False
        Transparent = True
      end
      object ALLabel43234: TcxLabel
        Left = 367
        Top = 46
        Caption = 'Flags'
        ParentFont = False
        Transparent = True
      end
      object ALEditMemCachedFlags: TcxTextEdit
        Left = 402
        Top = 45
        TabOrder = 24
        Text = '<#randomnumber>'
        Width = 215
      end
      object cxLabel5: TcxLabel
        Left = 344
        Top = 70
        Caption = 'Expiration'
        ParentFont = False
        Transparent = True
      end
      object ALEditMemCachedExpTime: TcxTextEdit
        Left = 403
        Top = 69
        TabOrder = 26
        Text = '<#randomnumber>'
        Width = 214
      end
      object ALButtonMemcachedDelete: TcxButton
        Left = 805
        Top = 80
        Width = 161
        Height = 25
        Caption = 'DELETE'
        TabOrder = 27
        OnClick = ALButtonMemcachedDeleteClick
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 144
    Top = 656
  end
  object dxSkinController1: TdxSkinController
    NativeStyle = False
    SkinName = 'Foggy'
    Left = 56
    Top = 648
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 328
    Top = 560
    PixelsPerInch = 96
    object cxStyle1: TcxStyle
      AssignedValues = [svColor]
      Color = clWhite
    end
  end
end
