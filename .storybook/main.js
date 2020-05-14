module.exports = {
  stories: ['../stories/**/*.re'],
  addons: ['@storybook/addon-actions', '@storybook/addon-links', "@storybook/addon-knobs/register"],
  webpack: async config => {
    config.module.rules.push({
      test: /\.(re|ml)$/,
      use: 'bs-loader'
    });
    config.resolve.extensions.push('.re', '.ml', '.js');
    return config
  }

};
