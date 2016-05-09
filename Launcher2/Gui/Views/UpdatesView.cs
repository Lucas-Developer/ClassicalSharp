﻿// ClassicalSharp copyright 2014-2016 UnknownShadow200 | Licensed under MIT
using System;
using System.Drawing;
using System.IO;
using ClassicalSharp;
using Launcher.Updater;
using OpenTK.Input;

namespace Launcher {
	
	public sealed class UpdatesView : IView {
		
		public DateTime LastStable, LastDev;
		internal int backIndex, relIndex, devIndex;
		
		public UpdatesView( LauncherWindow game ) : base( game ) {
			widgets = new LauncherWidget[13];
		}

		public override void Init() {
			titleFont = new Font( game.FontName, 16, FontStyle.Bold );
			inputFont = new Font( game.FontName, 14, FontStyle.Regular );
			MakeWidgets();
		}
		
		public override void DrawAll() {
			MakeWidgets();
			RedrawAllButtonBackgrounds();
			
			using( drawer ) {
				drawer.SetBitmap( game.Framebuffer );
				RedrawAll();
				FastColour col = LauncherSkin.ButtonBorderCol;
				int middle = game.Height / 2;
				game.Drawer.DrawRect( col, game.Width / 2 - 160, middle - 100, 320, 1 );
				game.Drawer.DrawRect( col, game.Width / 2 - 160, middle - 10, 320, 1 );
			}
			Dirty = true;
		}
		
		const string dateFormat = "dd-MM-yyyy HH:mm";
		void MakeWidgets() {
			widgetIndex = 0;
			string exePath = Path.Combine( Program.AppDirectory, "ClassicalSharp.exe" );
			
			MakeLabelAt( "Your build:", inputFont, Anchor.Centre, Anchor.Centre, -60, -120 );
			string yourBuild = File.GetLastWriteTime( exePath ).ToString( dateFormat );
			MakeLabelAt( yourBuild, inputFont, Anchor.Centre, Anchor.Centre, 70, -120 );
			
			MakeLabelAt( "Latest release:", inputFont, Anchor.Centre, Anchor.Centre, -70, -75 );
			string latestStable = GetDateString( LastStable );
			MakeLabelAt( latestStable, inputFont, Anchor.Centre, Anchor.Centre, 70, -75 );
			relIndex = widgetIndex;
			MakeButtonAt( "Direct3D 9", 130, 30, titleFont, Anchor.Centre, -80, -40 );
			MakeButtonAt( "OpenGL", 130, 30, titleFont, Anchor.Centre, 80, -40 );
			
			MakeLabelAt( "Latest dev build:", inputFont, Anchor.Centre, Anchor.Centre, -80, 15 );
			string latestDev = GetDateString( LastDev );
			MakeLabelAt( latestDev, inputFont, Anchor.Centre, Anchor.Centre, 70, 15 );
			devIndex = widgetIndex;
			MakeButtonAt( "Direct3D 9", 130, 30, titleFont, Anchor.Centre, -80, 50 );
			MakeButtonAt( "OpenGL", 130, 30, titleFont, Anchor.Centre, 80, 50 );
			
			MakeLabelAt( "&eDirect3D 9 is recommended for Windows.",
			            inputFont, Anchor.Centre, Anchor.Centre, 0, 105 );
			MakeLabelAt( "&eThe client must be closed before updating.",
			            inputFont, Anchor.Centre, Anchor.Centre, 0, 130 );
			
			backIndex = widgetIndex;
			MakeButtonAt( "Back", 80, 35, titleFont, Anchor.Centre, 0, 170 );
		}
		
		string GetDateString( DateTime last ) {
			if( last == DateTime.MaxValue ) return "Update check failed";
			if( last == DateTime.MinValue ) return "Checking..";	
			return last.ToString( dateFormat );
		}
	}
}