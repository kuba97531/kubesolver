using System;
using System.Drawing;

namespace KubeSolverGUI.Utils.Drawing
{
    public class DrawingUtils
    {
        public static Font DisplayFont = new Font(FontFamily.GenericSansSerif, 8);
        public static readonly Font DefaultFont = new Font(FontFamily.GenericSansSerif, 8);
        public static readonly int DefaultMinimumSize = 3;

        /// <summary>
        /// Attempts to draw some text.
        /// </summary>
        /// <param name="g">The graphics to draw into.</param>
        /// <param name="text">The text to draw.</param>
        /// <param name="referenceString">
        /// A reference string to use for font size selection. By setting it to the same value across multiple calls you can make
        /// sure that the font size used is the same.
        /// </param>
        /// <param name="rectangle">The rectangle into which the text should fit.</param>
        /// <param name="alignment">How the text should be aligned left/right.</param>
        /// <param name="lineAlignment">How the text should be aligned top/bottom.</param>
        /// <param name="brush">The brush to use.</param>
        /// <param name="font">The font to use.</param>
        /// <param name="minimumAllowedSize">Smallest allowed font size.</param>
        /// <param name="maxSize">Largest allowed font size.</param>
        /// <returns>
        /// True if the text could be drawn with the provided parameters, false otherwise (for example if it's too long).
        /// </returns>
        public static bool DrawAlignedString(Graphics g, string text, string referenceString, Rectangle rectangle, StringAlignment alignment = StringAlignment.Near, StringAlignment lineAlignment = StringAlignment.Near, Brush brush = null, Font font = null, int minimumAllowedSize = -1, int maxSize = int.MaxValue)
        {
            if (string.IsNullOrWhiteSpace(text)) return true;
            if (font == null)
            {
                font = DisplayFont;
            }
            if (brush == null)
            {
                brush = SystemBrushes.WindowText;
            }

            if (minimumAllowedSize == -1)
            {
                minimumAllowedSize = DefaultMinimumSize;
            }

            //if (lineAlignment == StringAlignment.Center)
            //{
            //    lineAlignment = alignment;
            //}

            if (rectangle.Width < 5 || rectangle.Height < 5)
            {
                return false;
            }

            var stringFormat = new StringFormat
            {
                Alignment = alignment,
                LineAlignment = lineAlignment
            };

            var enhancedFont = FindFont(g, rectangle.Size, font, new[] { text, referenceString });
            if (enhancedFont.Size >= minimumAllowedSize)
            {
                if (enhancedFont.Size > maxSize)
                {
                    enhancedFont = new Font(enhancedFont.FontFamily, maxSize, enhancedFont.Style);
                }
                g.DrawString(text, enhancedFont, brush, rectangle, stringFormat);
                return true;
            }
            return false;
        }

        /// <summary>
        /// Returns the smallest font for all provided strings
        /// </summary>
        /// <param name="g"></param>
        /// <param name="room"></param>
        /// <param name="preferedFont"></param>
        /// <param name="strings"></param>
        /// <returns></returns>
        private static Font FindFont(Graphics g, Size room, Font preferedFont, string[] strings)
        {
            if (strings.Length == 0) throw new ArgumentException();
            var result = FindFont(g, strings[0], room, preferedFont);

            for (int i = 1; i < strings.Length; i++)
            {
                var f = FindFont(g, strings[i], room, preferedFont);
                if (f.Size < result.Size)
                {
                    result = f;
                }
            }
            return result;
        }

        //thanks to http://stackoverflow.com/questions/19674743/dynamically-resizing-font-to-fit-space-while-using-graphics-drawstring
        private static Font FindFont(Graphics g, string longString, Size room, Font preferedFont)
        {
            var RealSize = g.MeasureString(longString ?? ".", preferedFont);
            float HeightScaleRatio = room.Height / RealSize.Height;
            float WidthScaleRatio = room.Width / RealSize.Width;
            float ScaleRatio = HeightScaleRatio < WidthScaleRatio ? HeightScaleRatio : WidthScaleRatio;
            float ScaleFontSize = preferedFont.Size * ScaleRatio;
            return new Font(preferedFont.FontFamily, ScaleFontSize, preferedFont.Style);
        }
    }
}
