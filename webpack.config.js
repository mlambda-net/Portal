const path = require("path")
const HtmlWebpackPlugin = require("html-webpack-plugin")
const outputDir = path.join(__dirname, "build/")

const isProd = process.env.NODE_ENV === "production"

module.exports = {
  entry: "./src/Index.re",
  mode: isProd ? "production" : "development",
  devtool: "source-map",
  output: {
    path: outputDir,
    filename: "[name].bundle.js"
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: "src/index.html",
      inject: true
    })
  ],
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 8000,
    historyApiFallback: true
  },
  resolve: {
    extensions: ['.re', '.ml', '.js']
  },
  module: {
    rules: [
      {
        test: /\.(re|ml)$/,
        use: 'bs-loader'
      },
      {
        test: /\.css$/,
        use: [
          "css-loader",
        ]
      },
      {
        test: /\.styl$/,
        use: [
          'css-loader',
          'stylus-loader',
        ]
      },
      {
        test: /\.js$/,
        exclude: /node_modules/,
        use: {
          loader: 'babel-loader'
        }
      }
    ]
  }
}
