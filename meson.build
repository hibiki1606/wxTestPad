project('wxTestPad', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3']
)

wx_dep = dependency(
  'wxwidgets', version : '>=3.0.0',
)

sources = files(
  'gui/buildergen/TpGUI.cpp',
  'gui/TpGUIMainFrame.cpp',
  'notepad/Notepad.cpp',
  'utilities/TpLogFormatter.cpp',
  'wxtestpad.cpp',
)

executable('wxTestPad', sources,
  dependencies : [wx_dep],
  install : false
)
